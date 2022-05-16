/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvt_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepiney <llepiney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 01:39:44 by llepiney          #+#    #+#             */
/*   Updated: 2022/05/16 18:46:46 by llepiney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	mvt_display(t_solong *s)
{
	char	*n;
	char	*msg;
	char	*res;

	n = ft_itoa(s->mvt);
	msg = ft_strdup("Movements ");
	res = ft_strjoin(msg, n);
	free(msg);
	free(n);
	mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->wall, 64, 0);
	mlx_string_put(s->mlx_ptr, s->mlx_win, 9, 18, 0xFFFFFF, res);
	mlx_string_put(s->mlx_ptr, s->mlx_win, 10, 19, 0x000000, res);
	free(res);
}
