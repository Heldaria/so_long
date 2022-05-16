/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepiney <llepiney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 21:18:04 by llepiney          #+#    #+#             */
/*   Updated: 2022/05/16 20:20:17 by llepiney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	put_image(t_solong *s)
{
	int	x;

	x = 32;
	s->grass = mlx_xpm_file_to_image(s->mlx_ptr, "mn/img/grass.xpm", &x, &x);
	s->wall = mlx_xpm_file_to_image(s->mlx_ptr, "mn/img/sakura.xpm", &x, &x);
	s->chkn = mlx_xpm_file_to_image(s->mlx_ptr, "mn/img/chkngrass.xpm", &x, &x);
	s->hole = mlx_xpm_file_to_image(s->mlx_ptr, "mn/img/holegrass.xpm", &x, &x);
	s->buck[0] = mlx_xpm_file_to_image(s->mlx_ptr, "mn/img/bf1.xpm", &x, &x);
	s->buck[3] = mlx_xpm_file_to_image(s->mlx_ptr, "mn/img/bb1.xpm", &x, &x);
	s->buck[6] = mlx_xpm_file_to_image(s->mlx_ptr, "mn/img/bl1.xpm", &x, &x);
	s->buck[9] = mlx_xpm_file_to_image(s->mlx_ptr, "mn/img/br1.xpm", &x, &x);
}

int	safe_image(t_solong *s)
{
	if (!(s->grass && s->wall && s->chkn && s->hole))
		return (error_msg("Error : could not create image.\n"));
	if (!(s->buck[0] && s->buck[3] && s->buck[6] && s->buck[9]))
		return (error_msg("Error : could not create image.\n"));
	return (1);
}
