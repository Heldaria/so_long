/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepiney <llepiney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 18:30:26 by llepiney          #+#    #+#             */
/*   Updated: 2022/05/05 23:50:30 by llepiney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void move_up(t_solong *s)
{
    if (s->map[s->x - 1][s->y] != '1' && s->map[s->x - 1][s->y] != 'E')
    {
        if (s->map[s->x - 1][s->y] == 'C')
        {
            s->item_count += 1;
            s->map[s->x - 1][s->y] = '0';
        }
        mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->buck[1], s->y * 32, (s->x - 1) * 32);
        mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->grass, s->y * 32, s->x * 32);
        s->x -= 1;
    }
    else if (s->map[s->x - 1][s->y] == 'E' && s->item_count == s->ccount)
    {
        // mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->out[1], s->y* 32, (s->x - 1)* 32);
        // mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->grass, s->y * 32, s->x * 32);
        close_window(s);
    }
}

void move_down(t_solong *s)
{
    if (s->map[s->x + 1][s->y] != '1' && s->map[s->x + 1][s->y] != 'E')
    {
        if (s->map[s->x + 1][s->y] == 'C')
        {
            s->item_count += 1;
            s->map[s->x + 1][s->y] = '0';
        }
        mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->buck[0], s->y * 32, (s->x + 1) * 32);
        mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->grass, s->y * 32, s->x * 32);
        s->x += 1;
    }
    else if (s->map[s->x + 1][s->y] == 'E' && s->item_count == s->ccount)
    {
        // mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->out[0], s->y* 32, (s->x + 1) * 32);
        // mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->grass, s->y * 32, s->x * 32);
        close_window(s);
    }
}

void move_left(t_solong *s)
{
    if (s->map[s->x][s->y - 1] != '1' && s->map[s->x][s->y - 1] != 'E')
    {
        if (s->map[s->x][s->y - 1] == 'C')
        {
            s->item_count += 1;
            s->map[s->x][s->y- 1] = '0';
        }
        mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->buck[2], (s->y - 1) * 32, s->x * 32);
        mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->grass, s->y * 32, s->x * 32);
        s->y -= 1;
    }
    else if (s->map[s->x][s->y - 1] == 'E' && s->item_count == s->ccount)
    {
        // mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->out[2], (s->y - 1)* 32, s->x * 32);
        // mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->grass, s->y * 32, s->x * 32);
        close_window(s);
    }
}

void move_right(t_solong *s)
{
    if (s->map[s->x][s->y + 1] != '1' && s->map[s->x][s->y + 1] != 'E')
    {
        if (s->map[s->x][s->y + 1] == 'C')
        {
            s->item_count += 1;
            s->map[s->x][s->y + 1] = '0';
        }
        mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->buck[3], (s->y + 1)* 32, s->x * 32);
        mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->grass, s->y * 32, s->x * 32);
        s->y += 1;
    }
    else if (s->map[s->x][s->y + 1] == 'E' && s->item_count == s->ccount)
    {
        // mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->out[3], (s->y + 1)* 32, s->x * 32);
        // mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->grass, s->y * 32, s->x * 32);
        close_window(s);
    }
}