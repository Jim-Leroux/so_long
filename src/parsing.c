/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jileroux <jileroux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:53:47 by jileroux          #+#    #+#             */
/*   Updated: 2023/01/13 17:33:13 by jileroux         ###   ########.fr       */
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

int	parsing_map(char *filename, char **argv)
{
	int		fd;
	int		index;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (write(2, "Error: can't open file\n", 23), 0);
	index = 0;
	line = get_next_line(fd);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
	}
	return (1);
}

int	parsing_line_map(char *line, int index)
{
	int		i;

	i = 0;
	while (line)
	{
		if (index == 0)
		{
			if (line[i++] != 0)
				return (write(2, "Error : Border is not a wall\n", 29), 0);
		}
		if (index > 0 && index < ft_strlen(line))
		{
			if (line[i] != '1' && line[i] != '0' && line[i] != 'C'
				&& line[i] != 'E' && line[i] != 'P')
				return (write(2, "Wrong caracter in map\n", 22), 0);
			i++;
		}
	}
	return (1);
}
