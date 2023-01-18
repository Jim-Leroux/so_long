/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jileroux <jileroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:31:33 by jileroux          #+#    #+#             */
/*   Updated: 2023/01/18 17:15:45 by jileroux         ###   ########.fr       */
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
	map->vertical = 0;
	map->exit = 0;
	map->mlx = NULL;
	map->image->pikachu = NULL;
	map->image->ground = NULL;
	map->image->berry = NULL;
	map->image->exit = NULL;
	map->image->wall = NULL;
	return (1);
}

int	put_image(t_data *data, t_map *map, void *mlx_win)
{
	if (data->line[map->horizontal] == '1')
		mlx_put_image_to_window(map->mlx, mlx_win, map->image->wall,
			map->horizontal * 64, map->vertical * 64);
	if (data->line[map->horizontal] == '0')
		mlx_put_image_to_window(map->mlx, mlx_win, map->image->ground,
			map->horizontal * 64, map->vertical * 64);
	if (data->line[map->horizontal] == 'C')
		mlx_put_image_to_window(map->mlx, mlx_win, map->image->berry,
			map->horizontal * 64, map->vertical * 64);
	if (data->line[map->horizontal] == 'P')
		mlx_put_image_to_window(map->mlx, mlx_win, map->image->pikachu,
			map->horizontal * 64, map->vertical * 64);
	if (data->line[map->horizontal] == 'E')
		mlx_put_image_to_window(map->mlx, mlx_win, map->image->exit,
			map->horizontal * 64, map->vertical * 64);
	return (1);
}
