/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ghost_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepiney <llepiney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 02:17:23 by llepiney          #+#    #+#             */
/*   Updated: 2022/05/08 02:19:55 by llepiney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ghost_display_up(t_solong *s, int i, int j)
{
	if (s->frame % 3 == 0)
		mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->ghost[0],
			j * 32, i * 32);
	if (s->frame % 3 == 1)
		mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->ghost[1],
			j * 32, i * 32);
	if (s->frame % 3 == 2)
		mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->ghost[2],
			j * 32, i * 32);
}

void	ghost_display_down(t_solong *s, int i, int j)
{
	if (s->frame % 3 == 0)
		mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->ghost[3],
			j * 32, i * 32);
	if (s->frame % 3 == 1)
		mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->ghost[4],
			j * 32, i * 32);
	if (s->frame % 3 == 2)
		mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->ghost[5],
			j * 32, i * 32);
}

void	ghost_display_right(t_solong *s, int i, int j)
{
	if (s->frame % 3 == 0)
		mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->ghost[6],
			j * 32, i * 32);
	if (s->frame % 3 == 1)
		mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->ghost[7],
			j * 32, i * 32);
	if (s->frame % 3 == 2)
		mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->ghost[8],
			j * 32, i * 32);
}

void	ghost_display_left(t_solong *s, int i, int j)
{
	if (s->frame % 3 == 0)
		mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->ghost[9],
			j * 32, i * 32);
	if (s->frame % 3 == 1)
		mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->ghost[10],
			j * 32, i * 32);
	if (s->frame % 3 == 2)
		mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->ghost[11],
			j * 32, i * 32);
}
