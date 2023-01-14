/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jileroux <jileroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:53:47 by jileroux          #+#    #+#             */
/*   Updated: 2023/01/14 17:21:44 by jileroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	parsing(int argc, char **argv, t_data *data, void *mlx)
{
	if (argc != 2)
		return (write(2, "Error: Wrong arguments\n", 23), 0);
	if (data == NULL)
		return (write(2, "Error: Structure malloc\n", 24), 0);
	if (parsing_extension(argv[1]) == 0)
		return (write(2, "Error: Wrong file extension\n", 28), 0);
	if (mlx == NULL)
		return (write(2, "Error: mlx not initialised\n", 27), 0);
	return (1);
}

int	parsing_extension(char *filename)
{
	int	i;

	while (filename[i])
		i++;
	i = i - 4;
	if (filename[i] == '.' && filename[i + 1] == 'b' && filename[i + 2] == 'e'
		&& filename[i + 3] == 'r')
		return (1);
	return (0);
}

int	parsing_stack(char *filename, char **argv, t_data **data)
{
	int		fd;
	int		index;
	char	*line;
	t_data	*tmp;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (write(2, "Error: can't open file\n", 23), 0);
	index = 0;
	(*data) = lst_new(get_next_line(fd));
	while (1)
	{
		tmp = lst_new(get_next_line(fd));
		line = get_next_line(fd);
		ft_lstadd_back(data, tmp);
		tmp = tmp->next;
		if (line == NULL)
			break ;
	}
	return (1);
}

int	parsing_map(t_data *data)
{
	if (parsing_first_and_last_line_map(data) == 0)
		return (0);
	data = data->next;
	while (data->next->next)
	{
		if (parsing_character(data) == 0 || parsing_border(data) == 0)
			return (0);
		data = data->next;
	}
	if (parsing_first_and_last_line_map(data) == 0)
		return (0);
}

int	parsing_first_and_last_line(t_data *data)
{
	int		i;

	i = 0;
	while (data->line[i])
	{
		if (data->line[i++] != '1')
			return (write(2, "Error: border is not a wall\n", 28), 0);
	}
	return (1);
}
