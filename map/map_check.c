/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepiney <llepiney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 18:07:09 by llepiney          #+#    #+#             */
/*   Updated: 2022/04/29 17:16:58 by llepiney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	line_numb(char **map)
{
	int	size;

	size = 0;
	while (map[size])
		size++;
	return (size);
}

int	col_numb(char **map)
{
	int	size;

	size = 0;
	while (map[0][size])
		size++;
	return (size);
}

int	wall_valid(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((i == 0 || i == (line_numb(map) - 1)) && map[i][j] != 'w' && map[i][j] != '\n')
				return (0);
			if ((j == 0 || j == (col_numb(map) - 1)) && map[i][j] != 'w' && map[i][j] != '\n')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_rect(char **map)
{
	int	i;
	int	j;
	int	lines;
	int	cols;

	i = 0;
	lines = line_numb(map);
	cols = col_numb(map);
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j])
			j++;
		if (j != cols)
			return (0);
		i++;
	}
	if (i != lines)
		return (0);
	return (1);
}