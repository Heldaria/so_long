/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepiney <llepiney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 21:18:04 by llepiney          #+#    #+#             */
/*   Updated: 2022/05/16 20:40:10 by llepiney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	put_image2(t_solong *s)
{
	int	x;

	x = 32;
	s->poison = mlx_xpm_file_to_image(s->mlx_ptr, "bn/img/poison.xpm", &x, &x);
	s->white = mlx_xpm_file_to_image(s->mlx_ptr, "bn/img/white.xpm", &x, &x);
	s->lose = mlx_xpm_file_to_image(s->mlx_ptr, "bn/img/lose.xpm", &x, &x);
	s->win = mlx_xpm_file_to_image(s->mlx_ptr, "bn/img/win.xpm", &x, &x);
	s->ghost[0] = mlx_xpm_file_to_image(s->mlx_ptr, "bn/img/gf1.xpm", &x, &x);
	s->ghost[1] = mlx_xpm_file_to_image(s->mlx_ptr, "bn/img/gf2.xpm", &x, &x);
	s->ghost[2] = mlx_xpm_file_to_image(s->mlx_ptr, "bn/img/gf3.xpm", &x, &x);
	s->ghost[3] = mlx_xpm_file_to_image(s->mlx_ptr, "bn/img/gb1.xpm", &x, &x);
	s->ghost[4] = mlx_xpm_file_to_image(s->mlx_ptr, "bn/img/gb2.xpm", &x, &x);
	s->ghost[5] = mlx_xpm_file_to_image(s->mlx_ptr, "bn/img/gb3.xpm", &x, &x);
	s->ghost[6] = mlx_xpm_file_to_image(s->mlx_ptr, "bn/img/gl1.xpm", &x, &x);
	s->ghost[7] = mlx_xpm_file_to_image(s->mlx_ptr, "bn/img/gl2.xpm", &x, &x);
	s->ghost[8] = mlx_xpm_file_to_image(s->mlx_ptr, "bn/img/gl3.xpm", &x, &x);
	s->ghost[9] = mlx_xpm_file_to_image(s->mlx_ptr, "bn/img/gr1.xpm", &x, &x);
	s->ghost[10] = mlx_xpm_file_to_image(s->mlx_ptr, "bn/img/gr2.xpm", &x, &x);
	s->ghost[11] = mlx_xpm_file_to_image(s->mlx_ptr, "bn/img/gr3.xpm", &x, &x);
}

void	put_image(t_solong *s)
{
	int	x;

	x = 32;
	s->grass = mlx_xpm_file_to_image(s->mlx_ptr, "bn/img/grass.xpm", &x, &x);
	s->wall = mlx_xpm_file_to_image(s->mlx_ptr, "bn/img/sakura.xpm", &x, &x);
	s->chkn = mlx_xpm_file_to_image(s->mlx_ptr, "bn/img/chkn.xpm", &x, &x);
	s->hole = mlx_xpm_file_to_image(s->mlx_ptr, "bn/img/hole.xpm", &x, &x);
	s->tree = mlx_xpm_file_to_image(s->mlx_ptr, "bn/img/tree.xpm", &x, &x);
	s->root = mlx_xpm_file_to_image(s->mlx_ptr, "bn/img/root.xpm", &x, &x);
	s->bush = mlx_xpm_file_to_image(s->mlx_ptr, "bn/img/bush.xpm", &x, &x);
	s->rock = mlx_xpm_file_to_image(s->mlx_ptr, "bn/img/rock.xpm", &x, &x);
	s->buck[0] = mlx_xpm_file_to_image(s->mlx_ptr, "bn/img/bf1.xpm", &x, &x);
	s->buck[1] = mlx_xpm_file_to_image(s->mlx_ptr, "bn/img/bf2.xpm", &x, &x);
	s->buck[2] = mlx_xpm_file_to_image(s->mlx_ptr, "bn/img/bf3.xpm", &x, &x);
	s->buck[3] = mlx_xpm_file_to_image(s->mlx_ptr, "bn/img/bb1.xpm", &x, &x);
	s->buck[4] = mlx_xpm_file_to_image(s->mlx_ptr, "bn/img/bb2.xpm", &x, &x);
	s->buck[5] = mlx_xpm_file_to_image(s->mlx_ptr, "bn/img/bb3.xpm", &x, &x);
	s->buck[6] = mlx_xpm_file_to_image(s->mlx_ptr, "bn/img/bl1.xpm", &x, &x);
	s->buck[7] = mlx_xpm_file_to_image(s->mlx_ptr, "bn/img/bl2.xpm", &x, &x);
	s->buck[8] = mlx_xpm_file_to_image(s->mlx_ptr, "bn/img/bl3.xpm", &x, &x);
	s->buck[9] = mlx_xpm_file_to_image(s->mlx_ptr, "bn/img/br1.xpm", &x, &x);
	s->buck[10] = mlx_xpm_file_to_image(s->mlx_ptr, "bn/img/br2.xpm", &x, &x);
	s->buck[11] = mlx_xpm_file_to_image(s->mlx_ptr, "bn/img/br3.xpm", &x, &x);
	put_image2(s);
}

int	safe_image(t_solong *s)
{
	int	i;

	if (!(s->grass && s->wall && s->chkn && s->hole))
		return (error_msg("Error : could not create image.\n"));
	if (!(s->tree && s->root && s->bush && s->rock))
		return (error_msg("Error : could not create image.\n"));
	if (!(s->white && s->lose && s->win))
		return (error_msg("Error : could not create image.\n"));
	i = 0;
	while (i < 12)
	{
		if (!s->buck[i] || !s->ghost[i])
			return (error_msg("Error : could not create image.\n"));
		i++;
	}
	return (1);
}
