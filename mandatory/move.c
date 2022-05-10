/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loan <loan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 18:30:26 by llepiney          #+#    #+#             */
/*   Updated: 2022/05/09 06:49:51 by loan             ###   ########.fr       */
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
        mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->buck[3], s->y * 32, (s->x - 1) * 32);
        mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->grass, s->y * 32, s->x * 32);
        s->x -= 1;
        s->mvt++;
        ft_putnbr(s->mvt);
        write(1, "\n", 1);
    }
    else if (s->map[s->x - 1][s->y] == 'E' && s->item_count == s->ccount)
        close_window(s);
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
        s->mvt++;
        ft_putnbr(s->mvt);
        write(1, "\n", 1);
    }
    else if (s->map[s->x + 1][s->y] == 'E' && s->item_count == s->ccount)
        close_window(s);
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
        mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->buck[6], (s->y - 1) * 32, s->x * 32);
        mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->grass, s->y * 32, s->x * 32);
        s->y -= 1;
        s->mvt++;
        ft_putnbr(s->mvt);
        write(1, "\n", 1);
    }
    else if (s->map[s->x][s->y - 1] == 'E' && s->item_count == s->ccount)
        close_window(s);
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
        mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->buck[9], (s->y + 1)* 32, s->x * 32);
        mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->grass, s->y * 32, s->x * 32);
        s->y += 1;
        s->mvt++;
        ft_putnbr(s->mvt);
        write(1, "\n", 1);
    }
    else if (s->map[s->x][s->y + 1] == 'E' && s->item_count == s->ccount)
        close_window(s);
}