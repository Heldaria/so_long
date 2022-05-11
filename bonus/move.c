/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepiney <llepiney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 18:30:26 by llepiney          #+#    #+#             */
/*   Updated: 2022/05/11 21:28:50 by llepiney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void move_up(t_solong *s)
{
    if (!is_in(s->map[s->x - 1][s->y], "1TRMBEGHJKX") && s->end == 0)
    {
        if (s->map[s->x - 1][s->y] == 'C')
        {
            s->item_count += 1;
            s->map[s->x - 1][s->y] = '0';
        }
        mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->buck[3], s->y * 32, (s->x - 1) * 32);
        mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->grass, s->y * 32, s->x * 32);
        s->x -= 1;
        s->mvt++;
        mvt_display(s);
        s->ori = 3;
    }
    else if (is_in(s->map[s->x - 1][s->y], "GHJKX"))
        s->end = 1;
    else if (s->map[s->x - 1][s->y] == 'E' && s->item_count == s->ccount)
        s->end = 2;
}

void move_down(t_solong *s)
{
    if (!is_in(s->map[s->x + 1][s->y], "1TRMBEGHJKX") && s->end == 0)
    {
        if (s->map[s->x + 1][s->y] == 'C')
        {
            s->item_count += 1;
            s->map[s->x + 1][s->y] = '0';
        }
        mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->buck[0], s->y * 32, (s->x + 1) * 32);
        mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->grass, s->y * 32, s->x * 32);
        s->x += 1;
        s->mvt++;
        mvt_display(s);
        s->ori = 0;
    }
    else if (is_in(s->map[s->x + 1][s->y], "GHJKX"))
        s->end = 1;
    else if (s->map[s->x + 1][s->y] == 'E' && s->item_count == s->ccount)
        s->end = 2;
}

void move_left(t_solong *s)
{
    if (!is_in(s->map[s->x][s->y - 1], "1TRMBEGHJKX") && s->end == 0)
    {
        if (s->map[s->x][s->y - 1] == 'C')
        {
            s->item_count += 1;
            s->map[s->x][s->y - 1] = '0';
        }
        mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->buck[6], (s->y - 1) * 32, s->x * 32);
        mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->grass, s->y * 32, s->x * 32);
        s->y -= 1;
        s->mvt++;
        mvt_display(s);
        s->ori = 6;
    }
    else if (is_in(s->map[s->x][s->y - 1], "GHJKX"))
        s->end = 1;
    else if (s->map[s->x][s->y - 1] == 'E' && s->item_count == s->ccount)
        s->end = 2;
}

void move_right(t_solong *s)
{
    if (!is_in(s->map[s->x][s->y + 1], "1TRMBEGHJKX") && s->end == 0)
    {
        if (s->map[s->x][s->y + 1] == 'C')
        {
            s->item_count += 1;
            s->map[s->x][s->y + 1] = '0';
        }
        mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->buck[9], (s->y + 1)* 32, s->x * 32);
        mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->grass, s->y * 32, s->x * 32);
        s->y += 1;
        s->mvt++;
        mvt_display(s);
        s->ori = 9;
    }
    else if (is_in(s->map[s->x][s->y + 1], "GHJKX"))
        s->end = 1;
    else if (s->map[s->x][s->y + 1] == 'E' && s->item_count == s->ccount)
        s->end = 2;
}