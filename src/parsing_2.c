/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jileroux <jileroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:04:27 by jileroux          #+#    #+#             */
/*   Updated: 2023/01/20 17:35:08 by jileroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	parsing_character(t_data *data)
{
	int	i;

	i = 0;
	while (data)
	{
		while (data->line[i] && data->line[i] != '\n')
		{
			if (data->line[i] != '0' && data->line[i] != '1'
				&& data->line[i] != 'C'
				&& data->line[i] != 'E' && data->line[i] != 'P')
				return (write(2, "Error : Wrong character in map\n", 31), 0);
			i++;
		}
		data = data->next;
	}
	return (1);
}

int	parsing_border(t_data *data)
{
	while (data)
	{
		if (data->line[0] != '1')
			return (write(2, "Error: border is not a wull\n", 28), 0);
		if (data->line[ft_strlen(data->line) - 2] != '1')
			return (write(2, "Error: border is not a well\n", 28), 0);
		data = data->next;
	}
	return (1);
}

int	parsing_size_and_format(t_data *data, t_map *map)
{
	int	vertical;
	int	horizontal;

	vertical = 0;
	horizontal = ft_strlen(data->line);
	while (data)
	{
		if (horizontal != ft_strlen(data->line))
			return (write(2, "Error : Map should be rectangular\n", 34), 0);
		data = data->next;
		vertical++;
	}
	if (vertical == horizontal)
		return (write(2, "Error : Map should be rectangular\n", 34), 0);
	if (vertical < 3 || horizontal < 3)
		return (write(2, "Error : Map too small to be played\n", 35), 0);
	map->horizontal = horizontal - 1;
	map->vertical = vertical;
	return (1);
}

int	parsing_minimal_map(t_data *data, t_map *map)
{
	int		i;

	while (data)
	{
		i = -1;
		while (data->line[++i])
		{
			if (data->line[i] == 'C')
				map->collectible++;
			if (data->line[i] == 'P')
				map->position++;
			if (data->line[i] == 'E')
				map->exit++;
		}
		data = data->next;
	}
	if (map->collectible < 1 || map->position < 1 || map->exit < 1)
		return (write(2, "Error : Map should at least have 1 collectible ", 47),
			write(2, "1 position and 1 exit\n", 22), 0);
	if (map->position > 1 || map->exit > 1)
		return (write(2, "Error : Map should only have 1 position ", 40),
			write(2, "and 1 exit\n", 11), 0);
	return (1);
}

int	parsing_img(t_image *image, void *mlx)
{
	int	size;

	size = 64;
	image->pikachu = mlx_xpm_file_to_image(mlx, PIKACHU, &size, &size);
	image->ground = mlx_xpm_file_to_image(mlx, GROUND, &size, &size);
	image->berry = mlx_xpm_file_to_image(mlx, BERRY, &size, &size);
	image->exit = mlx_xpm_file_to_image(mlx, EXIT, &size, &size);
	image->wall = mlx_xpm_file_to_image(mlx, WALL, &size, &size);
	if (image->pikachu == NULL || image->pikachu == NULL
		|| image->pikachu == NULL || image->pikachu == NULL
		|| image->pikachu == NULL)
		return (write(2, "Error : img can't be read\n", 26), 0);
	return (1);
}
