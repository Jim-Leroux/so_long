/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jileroux <jileroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:49:17 by jileroux          #+#    #+#             */
/*   Updated: 2023/01/22 15:12:47 by jileroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_map		*map;
	t_data		*data;

	map = malloc(sizeof(t_map));
	if (parsing(argc, argv, map, &data) == 0
		|| parsing_img(map->image, map->mlx) == 0)
		return (free(map), EXIT_FAILURE);
	if (list_to_tab(data, map) == 0)
		return (EXIT_FAILURE);
	if (is_valid_map(map) != (map->collectible + map->exit))
		return (free_invalid_map(map),
			write(2, "Error : map is not valid\n", 25), EXIT_FAILURE);
	map->mlx_win = mlx_new_window(map->mlx, map->horizontal * 64,
			map->vertical * 64, "so_long");
	map_render(map);
	mlx_hook(map->mlx_win, 2, 1L << 0, check_hook, map);
	mlx_hook(map->mlx_win, 17, 1L << 1, close_window, map);
	mlx_loop_hook(map->mlx, map_render, map);
	mlx_loop(map->mlx);
	free_data(map->data);
	free_all(map);
	return (EXIT_SUCCESS);
}

int	map_render(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->vertical)
	{
		j = 0;
		while (j < map->horizontal)
		{
			put_image(map, i, j);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_hook(int keycode, t_map *map)
{
	if (keycode == K_ESC)
		close_window(map);
	else
		ft_move_player(keycode, map);
	return (0);
}

void	ft_move_player(int keycode, t_map *map)
{
	int		moved;
	char	*move_count;

	moved = 0;
	if (keycode == K_W)
		moved = move_top(map);
	if (keycode == K_A)
		moved = move_left(map);
	if (keycode == K_S)
		moved = move_down(map);
	if (keycode == K_D)
		moved = move_right(map);
	move_count = ft_itoa(map->move_count);
	if (moved)
	{
		write(1, "Move : ", 7);
		write(1, move_count, strlen(move_count));
		write(1, "\n", 1);
	}
	free(move_count);
}

int	parsing_line(t_data **data, int fd)
{
	if (fd == -1)
		return (write(2, "Error: can't open file\n", 23), 0);
	(*data) = lst_new(get_next_line(fd, 0));
	if ((*data)->line == NULL)
		return (free(*data), close(fd),
			write(2, "Error: No map to read\n", 22), 0);
	if ((*data)->line[0] == '\n')
		return (free((*data)->line), free(*data), close(fd),
			write(2, "Error: No map to read\n", 22), 0);
	return (1);
}
