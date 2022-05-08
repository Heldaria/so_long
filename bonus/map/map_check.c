/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepiney <llepiney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 18:07:09 by llepiney          #+#    #+#             */
/*   Updated: 2022/05/08 03:33:41 by llepiney         ###   ########.fr       */
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

int	min_map(t_solong *s)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (s->map[i])
	{
		j = 0;
		while (s->map[i][j])
		{
			if (is_in(s->map[i][j], "01PCE"))
				count++;
			j++;
		}
	}
	if (count < 17)
		return(error_msg("Map too small or empty.\n"));
	return (1);
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
				return (error_msg("Error : invalid walls.\n"));
			if ((j == 0 || map[i][j + 1] == '\0' || map[i][j + 1] == '\n') && map[i][j] != '1' && map[i][j] != '\n')
				return (error_msg("Error : invalid walls.\n"));
			if (is_in(map[i][j], "GHJK"))
				s->ghost_nb++;
			j++;
		}
		i++;
	}
	if (s->ccount == 0 || s->ecount == 0 || s->pcount != 1)
		return (error_msg("Error : wrong map element(s).\n"));
	s->length = j * 32;
	s->width = i * 32;
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
			return (error_msg("Error : map not rectangle.\n"));
		i++;
	}
	return (1);
}