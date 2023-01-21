/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jileroux <jileroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:15:03 by jileroux          #+#    #+#             */
/*   Updated: 2023/01/21 12:47:49 by jileroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	is_valid(t_map *map, int i, int j)
{
	int	count;

	count = 0;
	if (map->visited[i][j] == 1)
		return (0);
	map->visited[i][j] = 1;
	if (map->map_array[i][j] == '1')
		return (0);
	if (map->map_array[i][j] == 'E' || map->map_array[i][j] == 'C')
		count++;
	if (map->visited[i - 1][j] == 0)
		count += is_valid(map, i - 1, j);
	if (map->visited[i + 1][j] == 0)
		count += is_valid(map, i + 1, j);
	if (map->visited[i][j - 1] == 0)
		count += is_valid(map, i, j - 1);
	if (map->visited[i][j + 1] == 0)
		count += is_valid(map, i, j + 1);
	return (count);
}

int	is_valid_map(t_map *map)
{
	map->visited = init_tab_visited(map);
	if (map->visited == NULL)
		return (0);
	return (is_valid(map, map->px, map->py));
}

void	find_player(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->vertical)
	{
		j = 0;
		while (j < map->horizontal)
		{
			if (map->map_array[i][j] == 'P')
			{
				map->px = i;
				map->py = j;
			}
			j++;
		}
		i++;
	}
}
