/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepiney <llepiney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 21:32:57 by llepiney          #+#    #+#             */
/*   Updated: 2022/05/16 20:39:10 by llepiney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	fill_map2(char c, t_solong *s, int i, int j)
{
	if (c == 'M')
		mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->root,
			j * 32, i * 32);
	else if (c == 'R')
		mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->rock,
			j * 32, i * 32);
	else if (c == 'B')
		mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->bush,
			j * 32, i * 32);
	else if (c == 'X')
		mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->poison,
			j * 32, i * 32);
	else if (c == 'G')
		mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->ghost[0],
			j * 32, i * 32);
}

static void	fill_map3(char c, t_solong *s, int i, int j)
{
	if (c == '1')
		mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->wall,
			j * 32, i * 32);
	else if (c == '0')
		mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->grass,
			j * 32, i * 32);
	else if (c == 'P')
		mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->buck[0],
			j * 32, i * 32);
	else if (c == 'C')
		mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->chkn,
			j * 32, i * 32);
	else if (c == 'E')
		mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->hole,
			j * 32, i * 32);
	else if (c == 'T')
		mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->tree,
			j * 32, i * 32);
	else if (c == 'H')
		mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->ghost[3],
			j * 32, i * 32);
}

int	fill_map(t_solong *s)
{
	int	i;
	int	j;

	i = 0;
	while (s->map[i])
	{
		j = 0;
		while (s->map[i][j])
		{
			if (s->map[i][j] == 'J')
				mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->ghost[6],
					j * 32, i * 32);
			else if (s->map[i][j] == 'K')
				mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->ghost[9],
					j * 32, i * 32);
			fill_map3(s->map[i][j], s, i, j);
			fill_map2(s->map[i][j], s, i, j);
			if (!is_in(s->map[i][j], "10PCETMRBXG\n"))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
