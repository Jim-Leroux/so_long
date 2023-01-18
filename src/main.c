/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jileroux <jileroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:49:17 by jileroux          #+#    #+#             */
/*   Updated: 2023/01/18 17:18:20 by jileroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_map		*map;
	t_data		*data;
	void		*mlx_win;

	data = malloc(sizeof(data));
	map = malloc(sizeof(t_map));
	if (parsing(argc, argv, map, &data) == 0
		|| parsing_img(map->image, map->mlx) == 0)
		return (EXIT_FAILURE);
	mlx_win = mlx_new_window(map->mlx, map->horizontal * 64,
			map->vertical * 64, "so_long");
	map_render(data, map, mlx_win);
	mlx_loop(map->mlx);
	return (EXIT_SUCCESS);
}

int	map_render(t_data *data, t_map *map, void *mlx_win)
{
	map->horizontal = 0;
	map->vertical = 0;
	while (data)
	{
		while (data->line[map->horizontal] != '\n'
			&& data->line[map->horizontal] != '\0')
		{
			put_image(data, map, mlx_win);
			map->horizontal++;
		}
		data = data->next;
		map->horizontal = 0;
		map->vertical++;
	}
	return (1);
}
