/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepiney <llepiney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 21:32:57 by llepiney          #+#    #+#             */
/*   Updated: 2022/05/05 23:52:10 by llepiney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	fill_map(t_solong *s)
{
	int	i;
	int	j;

	i = 0;
	while (s->map[i])
	{
		j = 0;
		while (s->map[i][j])
		{
			if (s->map[i][j] == '1')
				mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->wall, j * 32, i * 32);
			else if (s->map[i][j] == '0')
				mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->grass, j * 32, i * 32);
			else if (s->map[i][j] == 'P')
				mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->buck[0], j * 32, i * 32);
			else if (s->map[i][j] == 'C')
				mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->chkn, j * 32, i * 32);
			else if (s->map[i][j] == 'E')
				mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->hole, j * 32, i * 32);
			j++;
		}
		i++;
	}
	// s->map[i][j] = '0';
	// mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->img2, 0, 0);
}
