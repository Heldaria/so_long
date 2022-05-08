/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ghost_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepiney <llepiney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 01:06:19 by llepiney          #+#    #+#             */
/*   Updated: 2022/05/08 03:41:55 by llepiney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void    ghost_up(t_solong *s, int x, int y)
{
    if (!is_in(s->map[x - 1][y], "1TRMBXGHJKE"))
    {
        s->map[x - 1][y] = 'H';
        s->map[x][y] = '0';
        mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->ghost[3], s->y * 32, (s->x - 1) * 32);
        mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->grass, s->y * 32, s->x * 32);
    }
    else if (s->map[x - 1][y] == 'P')
        s->end = 1;
}

void    ghost_down(t_solong *s, int x, int y)
{
    if (!is_in(s->map[x + 1][y], "1TRMBXGHJKE"))
    {
        s->map[x + 1][y] = 'G';
        s->map[x][y] = '0';
        mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->ghost[0], s->y * 32, (s->x + 1) * 32);
        mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->grass, s->y * 32, s->x * 32);
    }
    else if (s->map[x + 1][y] == 'P')
        s->end = 1;
}

void    ghost_left(t_solong *s, int x, int y)
{
    if (!is_in(s->map[x][y - 1], "1TRMBXGHJKE"))
    {
        s->map[x][y - 1] = 'J';
        s->map[x][y] = '0';
        mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->ghost[6], (s->y - 1) * 32, s->x * 32);
        mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->grass, s->y * 32, s->x * 32);
    }
    else if (s->map[x][y - 1] == 'P')
        s->end = 1;
}

void    ghost_right(t_solong *s, int x, int y)
{
    if (!is_in(s->map[x][y + 1], "1TRMBXGHJKE"))
    {
        s->map[x][y + 1] = 'K';
        s->map[x][y] = '0';
        mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->ghost[9], (s->y + 1) * 32, s->x * 32);
        mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->grass, s->y * 32, s->x * 32);
    }
    else if (s->map[x][y + 1] == 'P')
        s->end = 1;
}