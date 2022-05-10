/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvt_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepiney <llepiney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 01:39:44 by llepiney          #+#    #+#             */
/*   Updated: 2022/05/11 01:57:18 by llepiney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long"

void    mvt_display(int mvt)
{
    char    *n;
    char    *msg;
    char    *res;

    n = ft_itoa(s->mvt);
    msg = ft_strdup("Movements : ");
    res = ft_strjoin(msg, n);
    free(msg);
    free(n);
    mlx_string_put(s->mlx_ptr, s->mlx_win, 15, 18, 0x00FBFF, res);
    free(res);
}