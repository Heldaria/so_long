/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buck.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepiney <llepiney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 02:34:37 by llepiney          #+#    #+#             */
/*   Updated: 2022/05/10 21:04:04 by llepiney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	buck_display(t_solong *s)
{
	if (s->frame % 3 == 0)
		mlx_put_image_to_window(s->mlx_ptr, s->mlx_win,
			s->buck[0 + s->ori], s->y * 32, s->x * 32);
	if (s->frame % 3 == 1)
		mlx_put_image_to_window(s->mlx_ptr, s->mlx_win,
			s->buck[1 + s->ori], s->y * 32, s->x * 32);
	if (s->frame % 3 == 2)
		mlx_put_image_to_window(s->mlx_ptr, s->mlx_win,
			s->buck[2 + s->ori], s->y * 32, s->x * 32);
}