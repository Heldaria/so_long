/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepiney <llepiney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:56:59 by llepiney          #+#    #+#             */
/*   Updated: 2022/05/16 20:24:06 by llepiney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	count_check(int i, int j, t_solong *s)
{
	if (s->map[i][j] == 'P')
	{
		s->x = i;
		s->y = j;
		s->pcount += 1;
	}
	else if (s->map[i][j] == 'C')
		s->ccount += 1;
	else if (s->map[i][j] == 'E')
		s->ecount += 1;
}
