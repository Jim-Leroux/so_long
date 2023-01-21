/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jileroux <jileroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:31:33 by jileroux          #+#    #+#             */
/*   Updated: 2023/01/21 18:36:43 by jileroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	init_struct(t_map *map)
{
	map->image = (t_image *)malloc(sizeof(t_image));
	if (map->image == NULL)
		return (write(2, "Error: Structure malloc\n", 24), 0);
	map->collectible = 0;
	map->horizontal = 0;
	map->position = 0;
	map->px = -1;
	map->py = -1;
	map->vertical = 0;
	map->move_count = 0;
	map->i = 0;
	map->j = 0;
	map->exit = 0;
	map->mlx = NULL;
	map->mlx_win = NULL;
	map->map_array = NULL;
	map->image->pikachu = NULL;
	map->image->ground = NULL;
	map->image->berry = NULL;
	map->image->exit = NULL;
	map->image->wall = NULL;
	return (1);
}

int	put_image(t_map *map, int i, int j)
{
	if (map->map_array[i][j] == '1')
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->image->wall,
			j * 64, i * 64);
	if (map->map_array[i][j] == '0')
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->image->ground,
			j * 64, i * 64);
	if (map->map_array[i][j] == 'C')
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->image->berry,
			j * 64, i * 64);
	if (map->map_array[i][j] == 'P')
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->image->pikachu,
			j * 64, i * 64);
	if (map->map_array[i][j] == 'E')
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->image->exit,
			j * 64, i * 64);
	return (1);
}

int	**init_tab_visited(t_map *map)
{
	int	i;
	int	j;
	int	x;
	int	**visited;

	x = 0;
	visited = malloc(sizeof(int *) * map->vertical + 1);
	if (visited == NULL)
		return (NULL);
	i = -1;
	while (++i < map->vertical)
	{
		j = -1;
		visited[i] = malloc(sizeof(int) * map->horizontal);
		if (visited[i] == NULL)
			return (NULL);
		while (++j < map->horizontal)
		{
			if (map->map_array[i][j] == '1')
				visited[i][j] = 1;
			else
				visited[i][j] = 0;
		}
	}
	return (visited);
}

char	**init_tab(t_map *map)
{
	int		i;
	char	**tab;

	tab = malloc(sizeof(char *) * map->vertical + 1);
	if (tab == NULL)
		return (0);
	i = -1;
	while (++i < map->vertical)
	{
		tab[i] = malloc(sizeof(char) * map->horizontal);
		if (tab[i] == NULL)
			return (0);
	}
	return (tab);
}

int	list_to_tab(t_data *data, t_map *map)
{
	int			i;
	int			j;
	t_data		*current;

	map->map_array = init_tab(map);
	if (map->map_array == NULL)
		return (0);
	current = data;
	i = -1;
	while (++i < map->vertical)
	{
		j = -1;
		while (++j < map->horizontal)
		{
			map->map_array[i][j] = current->line[j];
		}
		current = current->next;
	}
	find_player(map);
	return (1);
}
