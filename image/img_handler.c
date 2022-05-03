/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepiney <llepiney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 21:18:04 by llepiney          #+#    #+#             */
/*   Updated: 2022/05/03 22:02:10 by llepiney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_image(t_solong *s)
{
	int	x;

	x = 32;
	s->img1 = mlx_xpm_file_to_image(s->mlx_ptr, "image/grass.xpm", &x, &x);
	s->img2 = mlx_xpm_file_to_image(s->mlx_ptr, "image/stone.xpm", &x, &x);
	s->img3 = mlx_xpm_file_to_image(s->mlx_ptr, "image/Background.xpm", &x, &x);
}