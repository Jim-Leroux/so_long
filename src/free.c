/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jileroux <jileroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:56:31 by jileroux          #+#    #+#             */
/*   Updated: 2023/01/22 15:14:03 by jileroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_tab(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->vertical)
	{
		free(map->visited[i]);
		i++;
	}
	free(map->visited);
}

void	free_char_tab(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->vertical)
	{
		free(map->map_array[i]);
		i++;
	}
	free(map->map_array);
}

void	free_data(t_data *data)
{
	t_data	*tmp;

	tmp = data;
	while (tmp)
	{
		tmp = data->next;
		free(data->line);
		free(data);
		data = tmp;
	}
}

void	free_all(t_map *map)
{
	free_char_tab(map);
	free(map->image);
	free(map->mlx);
	free_tab(map);
	free(map);
}

void	free_invalid_map(t_map *map)
{
	free_char_tab(map);
	free_tab(map);
	close_img(map);
	mlx_destroy_display(map->mlx);
	free(map->mlx);
	free_data(map->data);
	free(map->image);
	free(map);
}
