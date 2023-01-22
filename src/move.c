/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jileroux <jileroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 18:25:12 by jileroux          #+#    #+#             */
/*   Updated: 2023/01/22 13:38:34 by jileroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	move_top(t_map *map)
{
	char	*move_count;

	if (map->map_array[map->px - 1][map->py] != '1')
	{
		if (map->map_array[map->px - 1][map->py] == 'C')
			map->collectible--;
		if (map->map_array[map->px - 1][map->py] == 'E'
			&& map->collectible > 0)
			return (0);
		else if (map->map_array[map->px - 1][map->py] == 'E'
			&& map->collectible == 0)
		{
			write (1, "Move : ", 7);
			move_count = ft_itoa(++map->move_count);
			write(1, move_count, ft_strlen(move_count));
			write(1, "\n", 1);
			free(move_count);
			close_window(map);
		}
		map->map_array[map->px - 1][map->py] = 'P';
		map->map_array[map->px][map->py] = '0';
		map->px--;
		return ((map->move_count++), 1);
	}
	return (0);
}

int	move_left(t_map *map)
{
	char	*move_count;

	if (map->map_array[map->px][map->py - 1] != '1')
	{
		if (map->map_array[map->px][map->py - 1] == 'C')
			map->collectible--;
		if (map->map_array[map->px][map->py - 1] == 'E'
		&& map->collectible != 0)
			return (0);
		else if (map->map_array[map->px][map->py - 1] == 'E'
			&& map->collectible == 0)
		{
			write (1, "Move : ", 7);
			move_count = ft_itoa(++map->move_count);
			write(1, move_count, ft_strlen(move_count));
			write(1, "\n", 1);
			free(move_count);
			close_window(map);
		}
		map->map_array[map->px][map->py - 1] = 'P';
		map->map_array[map->px][map->py] = '0';
		map->py--;
		return ((map->move_count++), 1);
	}
	return (0);
}

int	move_down(t_map *map)
{
	char	*move_count;

	if (map->map_array[map->px + 1][map->py] != '1')
	{
		if (map->map_array[map->px + 1][map->py] == 'C')
			map->collectible--;
		if (map->map_array[map->px + 1][map->py] == 'E'
			&& map->collectible > 0)
			return (0);
		else if (map->map_array[map->px + 1][map->py] == 'E'
			&& map->collectible == 0)
		{
			write (1, "Move : ", 7);
			move_count = ft_itoa(++map->move_count);
			write(1, move_count, ft_strlen(move_count));
			write(1, "\n", 1);
			free(move_count);
			close_window(map);
		}
		map->map_array[map->px + 1][map->py] = 'P';
		map->map_array[map->px][map->py] = '0';
		map->px++;
		return ((map->move_count++), 1);
	}
	return (0);
}

int	move_right(t_map *map)
{
	char	*move_count;

	if (map->map_array[map->px][map->py + 1] != '1')
	{
		if (map->map_array[map->px][map->py + 1] == 'C')
			map->collectible--;
		if (map->map_array[map->px][map->py + 1] == 'E'
			&& map->collectible > 0)
			return (0);
		else if (map->map_array[map->px][map->py + 1] == 'E'
			&& map->collectible == 0)
		{
			write (1, "Move : ", 7);
			move_count = ft_itoa(++map->move_count);
			write(1, move_count, ft_strlen(move_count));
			write(1, "\n", 1);
			free(move_count);
			close_window(map);
		}
		map->map_array[map->px][map->py + 1] = 'P';
		map->map_array[map->px][map->py] = '0';
		map->py++;
		return ((map->move_count++), 1);
	}
	return (0);
}
