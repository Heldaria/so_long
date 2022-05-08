/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepiney <llepiney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 21:18:04 by llepiney          #+#    #+#             */
/*   Updated: 2022/05/08 03:15:16 by llepiney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	put_image(t_solong *s)
{
	int	x;

	x = 32;
	s->grass = mlx_xpm_file_to_image(s->mlx_ptr, "mandatory/image/grass.xpm", &x, &x);
	s->wall = mlx_xpm_file_to_image(s->mlx_ptr, "mandatory/image/sakura.xpm", &x, &x);
	s->chkn = mlx_xpm_file_to_image(s->mlx_ptr, "mandatory/image/chkngrass.xpm", &x, &x);
	s->hole = mlx_xpm_file_to_image(s->mlx_ptr, "mandatory/image/holegrass.xpm", &x, &x);
	s->buck[0] = mlx_xpm_file_to_image(s->mlx_ptr, "mandatory/image/buckfront1.xpm", &x, &x);
	s->buck[3] = mlx_xpm_file_to_image(s->mlx_ptr, "mandatory/image/buckback1.xpm", &x, &x);
	s->buck[6] = mlx_xpm_file_to_image(s->mlx_ptr, "mandatory/image/buckleft1.xpm", &x, &x);
	s->buck[9] = mlx_xpm_file_to_image(s->mlx_ptr, "mandatory/image/buckright1.xpm", &x, &x);
}

int	safe_image(t_solong *s)
{
	if (!(s->grass && s->wall && s->chkn && s->hole))
		return (error_msg("Error : could not create image.\n"));
	if (!(s->buck[0] && s->buck[3] && s->buck[6] && s->buck[9]))
		return (error_msg("Error : could not create image.\n"));
	return (1);
}