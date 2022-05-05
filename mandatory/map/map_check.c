/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepiney <llepiney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 18:07:09 by llepiney          #+#    #+#             */
/*   Updated: 2022/05/05 23:16:47 by llepiney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

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

int	map_check(char **map, t_solong *s)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			count_check(i, j, s);
			if ((i == 0 || map[i + 1] == NULL) && map[i][j] != '1' && map[i][j] != '\n')
				return (0);
			if ((j == 0 || map[i][j + 1] == '\0' || map[i][j + 1] == '\n') && map[i][j] != '1' && map[i][j] != '\n')
				return (0);
			j++;
		}
		i++;
	}
	if (s->ccount == 0 || s->ecount == 0 || s->pcount != 1)
		return (0);
	s->length = j * 32;
	s->width = i * 32;
	return (1);
}

int	is_rect(char **map, t_solong *s)
{
	int	i;
	int	len1;
	int	len2;

	s->ccount = 0;
	s->ecount = 0;
	s->pcount = 0;
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