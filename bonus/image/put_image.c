/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepiney <llepiney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 21:18:04 by llepiney          #+#    #+#             */
/*   Updated: 2022/05/08 03:16:26 by llepiney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	put_image2(t_solong *s)
{
	int	x;

	x = 32;
	s->poison = mlx_xpm_file_to_image(s->mlx_ptr, "bonus/image/poisongrass.xpm", &x, &x);
	s->ghost[0] = mlx_xpm_file_to_image(s->mlx_ptr, "bonus/image/ghostfront1.xpm", &x, &x);
	s->ghost[1] = mlx_xpm_file_to_image(s->mlx_ptr, "bonus/image/ghostfront2.xpm", &x, &x);
	s->ghost[2] = mlx_xpm_file_to_image(s->mlx_ptr, "bonus/image/ghostfront3.xpm", &x, &x);
	s->ghost[3] = mlx_xpm_file_to_image(s->mlx_ptr, "bonus/image/ghostback1.xpm", &x, &x);
	s->ghost[4] = mlx_xpm_file_to_image(s->mlx_ptr, "bonus/image/ghostback2.xpm", &x, &x);
	s->ghost[5] = mlx_xpm_file_to_image(s->mlx_ptr, "bonus/image/ghostback3.xpm", &x, &x);
	s->ghost[6] = mlx_xpm_file_to_image(s->mlx_ptr, "bonus/image/ghostleft1.xpm", &x, &x);
	s->ghost[7] = mlx_xpm_file_to_image(s->mlx_ptr, "bonus/image/ghostleft2.xpm", &x, &x);
	s->ghost[8] = mlx_xpm_file_to_image(s->mlx_ptr, "bonus/image/ghostleft3.xpm", &x, &x);
	s->ghost[9] = mlx_xpm_file_to_image(s->mlx_ptr, "bonus/image/ghostright1.xpm", &x, &x);
	s->ghost[10] = mlx_xpm_file_to_image(s->mlx_ptr, "bonus/image/ghostright2.xpm", &x, &x);
	s->ghost[11] = mlx_xpm_file_to_image(s->mlx_ptr, "bonus/image/ghostright3.xpm", &x, &x);
}

void	put_image(t_solong *s)
{
	int	x;

	x = 32;
	s->grass = mlx_xpm_file_to_image(s->mlx_ptr, "bonus/image/grass.xpm", &x, &x);
	s->wall = mlx_xpm_file_to_image(s->mlx_ptr, "bonus/image/sakura.xpm", &x, &x);
	s->chkn = mlx_xpm_file_to_image(s->mlx_ptr, "bonus/image/chkngrass.xpm", &x, &x);
	s->hole = mlx_xpm_file_to_image(s->mlx_ptr, "bonus/image/holegrass.xpm", &x, &x);
	s->tree = mlx_xpm_file_to_image(s->mlx_ptr, "bonus/image/contreegrass.xpm", &x, &x);
	s->root = mlx_xpm_file_to_image(s->mlx_ptr, "bonus/image/rootgrass.xpm", &x, &x);
	s->bush = mlx_xpm_file_to_image(s->mlx_ptr, "bonus/image/bushgrass.xpm", &x, &x);
	s->rock = mlx_xpm_file_to_image(s->mlx_ptr, "bonus/image/rockgrass.xpm", &x, &x);
	s->buck[0] = mlx_xpm_file_to_image(s->mlx_ptr, "bonus/image/buckfront1.xpm", &x, &x);
	s->buck[1] = mlx_xpm_file_to_image(s->mlx_ptr, "bonus/image/buckfront2.xpm", &x, &x);
	s->buck[2] = mlx_xpm_file_to_image(s->mlx_ptr, "bonus/image/buckfront3.xpm", &x, &x);
	s->buck[3] = mlx_xpm_file_to_image(s->mlx_ptr, "bonus/image/buckback1.xpm", &x, &x);
	s->buck[4] = mlx_xpm_file_to_image(s->mlx_ptr, "bonus/image/buckback2.xpm", &x, &x);
	s->buck[5] = mlx_xpm_file_to_image(s->mlx_ptr, "bonus/image/buckback3.xpm", &x, &x);
	s->buck[6] = mlx_xpm_file_to_image(s->mlx_ptr, "bonus/image/buckleft1.xpm", &x, &x);
	s->buck[7] = mlx_xpm_file_to_image(s->mlx_ptr, "bonus/image/buckleft2.xpm", &x, &x);
	s->buck[8] = mlx_xpm_file_to_image(s->mlx_ptr, "bonus/image/buckleft2.xpm", &x, &x);
	s->buck[9] = mlx_xpm_file_to_image(s->mlx_ptr, "bonus/image/buckright1.xpm", &x, &x);
	s->buck[10] = mlx_xpm_file_to_image(s->mlx_ptr, "bonus/image/buckright2.xpm", &x, &x);
	s->buck[11] = mlx_xpm_file_to_image(s->mlx_ptr, "bonus/image/buckright3.xpm", &x, &x);
	put_image2(s);
}

int	safe_image(t_solong *s)
{
	int	i;

	if (!(s->grass && s->wall && s->chkn && s->hole))
		return (error_msg("Error : could not create image.\n"));
	if (!(s->tree && s->root && s->bush && s->rock))
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