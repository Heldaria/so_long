/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepiney <llepiney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:27:48 by llepiney          #+#    #+#             */
/*   Updated: 2022/05/06 00:15:42 by llepiney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char **argv)
{
	t_solong	*s;

	(void)argc;
	s = malloc(sizeof(t_solong *));
	s->map = map_create(argv);
	(void)argv;
	if (!is_rect(s->map, s) || !map_check(s->map, s))
	{
		printf("Error wall or rect.\n");
		return (0);
	}
	s->mlx_ptr = mlx_init();
	put_image(s);
	s->mlx_win = mlx_new_window(s->mlx_ptr, s->length, s->width, "so_long");
	fill_map(s);
	mlx_key_hook(s->mlx_win, key_act, s);
	mlx_loop(s->mlx_ptr);
	return (0);
}
