/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepiney <llepiney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 21:18:04 by llepiney          #+#    #+#             */
/*   Updated: 2022/05/06 00:17:50 by llepiney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	put_image(t_solong *s)
{
	int	x;

	x = 32;
	s->grass = mlx_xpm_file_to_image(s->mlx_ptr, "image/grass.xpm", &x, &x);
	s->wall = mlx_xpm_file_to_image(s->mlx_ptr, "image/wall.xpm", &x, &x);
	s->chkn = mlx_xpm_file_to_image(s->mlx_ptr, "image/chkngrass.xpm", &x, &x);
	s->hole = mlx_xpm_file_to_image(s->mlx_ptr, "image/holegrass.xpm", &x, &x);
	s->buck[0] = mlx_xpm_file_to_image(s->mlx_ptr, "image/buck/buckfront1.xpm", &x, &x);
	s->buck[1] = mlx_xpm_file_to_image(s->mlx_ptr, "image/buck/buckback1.xpm", &x, &x);
	s->buck[2] = mlx_xpm_file_to_image(s->mlx_ptr, "image/buck/buckleft1.xpm", &x, &x);
	s->buck[3] = mlx_xpm_file_to_image(s->mlx_ptr, "image/buck/buckright1.xpm", &x, &x);
	// (void)x;
	// (void)s;
}