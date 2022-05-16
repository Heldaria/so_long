/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ghost.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepiney <llepiney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 02:27:20 by llepiney          #+#    #+#             */
/*   Updated: 2022/05/16 18:45:33 by llepiney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ghost_display(t_solong *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s->map[i])
	{
		j = 0;
		while (s->map[i][j])
		{
			if (is_in(s->map[i][j], "GHJK"))
			{
				if (s->map[i][j] == 'G')
					ghost_display_down(s, i, j);
				if (s->map[i][j] == 'K')
					ghost_display_right(s, i, j);
				if (s->map[i][j] == 'H')
					ghost_display_up(s, i, j);
				if (s->map[i][j] == 'J')
					ghost_display_left(s, i, j);
			}
			j++;
		}
		i++;
	}
}

void	rand_move(t_solong *s, int i, int j)
{
	s->ghost_ori = rand() % 4;
	if (s->ghost_ori == 0 && s->map[i - 1][j] == '0')
		ghost_up(s, i, j);
	else if (s->ghost_ori == 1 && s->map[i + 1][j] == '0')
		ghost_down(s, i, j);
	else if (s->ghost_ori == 2 && s->map[i][j + 1] == '0')
		ghost_right(s, i, j);
	else if (s->ghost_ori == 3 && s->map[i][j - 1] == '0')
		ghost_left(s, i, j);
}

void	move_entity(t_solong *s, int i, int j, int g)
{
	int	moved;

	moved = (rand() % s->ghost_nb) + 1;
	while (s->map[i])
	{
		j = 0;
		while (s->map[i][j])
		{
			if (is_in(s->map[i][j], "GHJK"))
			{
				g++;
				if (g == moved)
				{
					rand_move(s, i, j);
					break ;
				}
			}
			j++;
		}
		i++;
	}
}
