/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jileroux <jileroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:04:27 by jileroux          #+#    #+#             */
/*   Updated: 2023/01/15 17:37:10 by jileroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	parsing_character(t_data *data)
{
	int	i;

	i = 0;
	while (data->line[i])
	{
		if (data->line[i] != '0' && data->line[i] != '1' && data->line[i] != 'C'
			&& data->line[i] != 'E' && data->line[i] != 'P')
			return (write(2, "Error : Wrong character in map\n", 31), 0);
	}
	return (1);
}

int	parsing_border(t_data *data)
{
	if (data->line[0] != '1')
		return (write(2, "Error: border is not a wull\n", 28), 0);
	if (data->line[ft_strlen(data->line)] != '1')
		return (write(2, "Error: border is not a well\n", 28), 0);
	return (1);
}

int	parsing_size_and_format(t_data *data)
{
	int	vertical;
	int	horizontal;

	vertical = 0;
	horizontal = ft_strlen(data->line);
	while (data)
	{
		if (horizontal != ft_strlen(data->line))
			return (write(2, "Error : Map should be rectangular\n", 34), 0);
		vertical++;
	}
	if (vertical == horizontal)
		return (write(2, "Error : Map should be rectangular\n", 34), 0);
	if (vertical < 3 || horizontal < 3)
		return (write(2, "Error : Map too small to be played\n", 35), 0);
	return (1);
}
