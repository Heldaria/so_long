/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_act.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepiney <llepiney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 18:11:09 by llepiney          #+#    #+#             */
/*   Updated: 2022/05/05 23:49:54 by llepiney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int  is_in(char c, char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (c == str[i])
            return (1);
        i++;
    }
    return (0);
}

int   key_act(int key, t_solong *s)
{
    if (is_in(key, "wasd"))
    {
        if (key == 'w')
            move_up(s);
        if (key == 'a')
            move_left(s);
        if (key == 's')
            move_down(s);
        if (key == 'd')
            move_right(s);
    }
    // else if (key == 65307)
	// 	close_window(s);
    return (0);
}