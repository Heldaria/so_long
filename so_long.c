/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepiney <llepiney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:27:48 by llepiney          #+#    #+#             */
/*   Updated: 2022/05/03 22:05:09 by llepiney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_solong	*s;

	(void)argc;
	s->mlx_ptr = mlx_init();
	s->mlx_win = mlx_new_window(mlx_ptr, 1920, 1080, "Hello world!");
	s->map = map_create(argv);
	put_image(s);
	if (!wall_valid(s->map) || !is_rect(s->map))
	{
		printf("Error wall or rect.\n");
		return (0);
	}
	fill_map(s);
	mlx_loop(s->mlx_ptr);
	return (0);
}
