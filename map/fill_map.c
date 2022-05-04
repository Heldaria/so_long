/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepiney <llepiney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 21:32:57 by llepiney          #+#    #+#             */
/*   Updated: 2022/05/03 22:06:06 by llepiney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
				mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->img1, j * 32, i * 32);
			else if (s->map[i][j] == '0')
				mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->img2, j * 32, i * 32);
			j++;
		}
		i++;
	}
	// s->map[i][j] = '0';
	// mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->img2, 0, 0);
}
