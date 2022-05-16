/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepiney <llepiney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:27:48 by llepiney          #+#    #+#             */
/*   Updated: 2022/05/16 20:41:37 by llepiney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	mini_main(t_solong *s)
{
	mlx_hook(s->mlx_win, 17, 0, close_window, s);
	mlx_key_hook(s->mlx_win, key_act, s);
	mlx_loop(s->mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_solong	s;

	if (argc != 2)
		return (error_msg("Error : wrong number of arguments.\n"));
	if (!name_check(argv[1]))
		return (error_msg("Error : invalid map format.\n"));
	init_value(&s);
	s.map = map_create(argv);
	if (!s.map)
		return (error_msg("Error : wrong or empty file.\n"));
	if (!is_rect(s.map) || !map_check(s.map, &s))
	{
		free_tab(s.map);
		return (0);
	}
	s.mlx_ptr = mlx_init();
	put_image(&s);
	if (!safe_image(&s))
		return (0);
	s.mlx_win = mlx_new_window(s.mlx_ptr, s.length, s.width, "so_long");
	if (fill_map(&s) == 0)
		return (error_msg("Error : wrong map elements.\n"));
	mini_main(&s);
	return (0);
}
