/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jileroux <jileroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 18:25:12 by jileroux          #+#    #+#             */
/*   Updated: 2023/01/21 18:37:17 by jileroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_top(t_map *map)
{
	if (map->map_array[map->px - 1][map->py] != '1')
	{
		if (map->map_array[map->px - 1][map->py] == 'C')
			map->collectible--;
		if (map->map_array[map->px - 1][map->py] == 'E'
			&& map->collectible > 0)
			return ;
		else if (map->map_array[map->px - 1][map->py] == 'E'
			&& map->collectible == 0)
			close_window(map);
		map->map_array[map->px - 1][map->py] = 'P';
		map->map_array[map->px][map->py] = '0';
		map->px--;
		map->move_count++;
	}
}

void	move_left(t_map *map)
{
	if (map->map_array[map->px][map->py - 1] != '1')
	{
		if (map->map_array[map->px][map->py - 1] == 'C')
			map->collectible--;
		if (map->map_array[map->px][map->py - 1] == 'E'
		&& map->collectible != 0)
			return ;
		else if (map->map_array[map->px][map->py - 1] == 'E'
			&& map->collectible == 0)
			close_window(map);
		map->map_array[map->px][map->py - 1] = 'P';
		map->map_array[map->px][map->py] = '0';
		map->py--;
		map->move_count++;
	}
}

void	move_down(t_map *map)
{
	if (map->map_array[map->px + 1][map->py] != '1')
	{
		if (map->map_array[map->px + 1][map->py] == 'C')
			map->collectible--;
		if (map->map_array[map->px + 1][map->py] == 'E'
			&& map->collectible > 0)
			return ;
		else if (map->map_array[map->px + 1][map->py] == 'E'
			&& map->collectible == 0)
			close_window(map);
		map->map_array[map->px + 1][map->py] = 'P';
		map->map_array[map->px][map->py] = '0';
		map->px++;
		map->move_count++;
	}
}

void	move_right(t_map *map)
{
	if (map->map_array[map->px][map->py + 1] != '1')
	{
		if (map->map_array[map->px][map->py + 1] == 'C')
			map->collectible--;
		if (map->map_array[map->px][map->py + 1] == 'E'
			&& map->collectible > 0)
			return ;
		else if (map->map_array[map->px][map->py + 1] == 'E'
			&& map->collectible == 0)
			close_window(map);
		map->map_array[map->px][map->py + 1] = 'P';
		map->map_array[map->px][map->py] = '0';
		map->py++;
		map->move_count++;
	}
}
