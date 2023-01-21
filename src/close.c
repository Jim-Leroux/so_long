/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jileroux <jileroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 12:21:00 by jileroux          #+#    #+#             */
/*   Updated: 2023/01/21 17:14:38 by jileroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	close_window(t_map *map)
{
	close_img(map);
	mlx_destroy_window(map->mlx, map->mlx_win);
	mlx_destroy_display(map->mlx);
	free_data(map->data);
	free_all(map);
	exit(1);
	return (0);
}

void	close_img(t_map *map)
{
	if (map->image->berry)
		mlx_destroy_image(map->mlx, map->image->berry);
	if (map->image->exit)
		mlx_destroy_image(map->mlx, map->image->exit);
	if (map->image->ground)
		mlx_destroy_image(map->mlx, map->image->ground);
	if (map->image->wall)
		mlx_destroy_image(map->mlx, map->image->wall);
	if (map->image->pikachu)
		mlx_destroy_image(map->mlx, map->image->pikachu);
}
