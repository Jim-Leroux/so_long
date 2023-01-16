/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jileroux <jileroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:04:27 by jileroux          #+#    #+#             */
/*   Updated: 2023/01/16 16:53:01 by jileroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	parsing_character(t_data *data)
{
	int	i;

	i = 0;
	while (data->line[i] && data->line[i] != '\n')
	{
		if (data->line[i] != '0' && data->line[i] != '1' && data->line[i] != 'C'
			&& data->line[i] != 'E' && data->line[i] != 'P')
			return (write(2, "Error : Wrong character in map\n", 31), 0);
		i++;
	}
	return (1);
}

int	parsing_border(t_data *data)
{
	if (data->line[0] != '1')
		return (write(2, "Error: border is not a wull\n", 28), 0);
	if (data->line[ft_strlen(data->line) - 2] != '1')
		return (write(2, "Error: border is not a well\n", 28), 0);
	return (1);
}

int	parsing_size_and_format(t_data *data)
{
	int	vertical;
	int	horizontal;

	vertical = 1;
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
	return (1);
}

int	parsing_minimal_map(t_data *data)
{
	int		i;
	t_data	*head;

	head = data;
	while (data)
	{
		i = -1;
		while (data->line[++i])
		{
			if (data->line[i] == 'C')
				head->collectible++;
			if (data->line[i] == 'P')
				head->position++;
			if (data->line[i] == 'E')
				head->exit++;
		}
		data = data->next;
	}
	if (head->collectible < 1 || head->position < 1 || head->exit < 1)
		return (write(2, "Error : Map should at least have 1 collectible ", 47),
			write(2, "1 position and 1 exit\n", 22), 0);
	if (head->position > 1 || head->exit > 1)
		return (write(2, "Error : Map should only have 1 position ", 40),
			write(2, "and 1 exit\n", 11), 0);
	return (1);
}
