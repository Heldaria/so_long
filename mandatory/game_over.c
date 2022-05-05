/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepiney <llepiney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 22:53:02 by llepiney          #+#    #+#             */
/*   Updated: 2022/05/05 23:17:50 by llepiney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int close_window(t_solong *s)
{
    mlx_loop_end(s->mlx_ptr);
	mlx_clear_window(s->mlx_ptr, s->mlx_win);
	mlx_destroy_window(s->mlx_ptr, s->mlx_win);
	mlx_destroy_display(s->mlx_ptr);
    exit(0);
}