/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepiney <llepiney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 18:07:09 by llepiney          #+#    #+#             */
/*   Updated: 2022/05/03 20:22:18 by llepiney         ###   ########.fr       */
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

static int	len_n(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int	wall_valid(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i + 1] != NULL)
	{
		j = 0;
		while (map[i][j])
		{
			if ((i == 0 || map[i + 1] == NULL) && map[i][j] != 'w' && map[i][j] != '\n')
				return (0);
			if ((j == 0 || map[i][j + 1] == '\0' || map[i][j + 1] == '\n') && map[i][j] != 'w' && map[i][j] != '\n')
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
	int	len1;
	int	len2;

	i = 1;
	len1 = len_n(map[0]);
	while (map[i])
	{
		len2 = len_n(map[i]);
		if (len1 != len2)
			return (0);
		i++;
	}
	return (1);
}