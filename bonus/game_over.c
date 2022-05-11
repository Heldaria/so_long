/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepiney <llepiney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 22:53:02 by llepiney          #+#    #+#             */
/*   Updated: 2022/05/11 23:00:14 by llepiney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	game_over(t_solong *s)
{
	int	i;
	int	j;

	i = 0;
	(void)i;
	(void)j;
	mlx_clear_window(s->mlx_ptr, s->mlx_win);
	while (i < s->width)
	{
		j = 0;
		while (j < s->length)
		{
			mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->white,
			j * 32, i * 32);
			j++;
		}
		i++;
	}
	if (s->end == 1)
	{
		mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->lose,
			(s->length / 2) - 124, (s->width / 2) - 68);
	}
	else if (s->end == 2)
	{
		mlx_put_image_to_window(s->mlx_ptr, s->mlx_win, s->win,
			(s->length / 2) - 96, (s->width / 2) - 62);
	}
	s->end = 3;
}

static void	destroy_all(t_solong *s)
{
	int	i;

	mlx_destroy_image(s->mlx_ptr, s->wall);
	mlx_destroy_image(s->mlx_ptr, s->grass);
	mlx_destroy_image(s->mlx_ptr, s->hole);
	mlx_destroy_image(s->mlx_ptr, s->chkn);
	mlx_destroy_image(s->mlx_ptr, s->poison);
	mlx_destroy_image(s->mlx_ptr, s->tree);
	mlx_destroy_image(s->mlx_ptr, s->rock);
	mlx_destroy_image(s->mlx_ptr, s->root);
	mlx_destroy_image(s->mlx_ptr, s->bush);
	mlx_destroy_image(s->mlx_ptr, s->white);
	mlx_destroy_image(s->mlx_ptr, s->lose);
	mlx_destroy_image(s->mlx_ptr, s->win);
	i = 0;
	while (i < 12)
		mlx_destroy_image(s->mlx_ptr, s->buck[i++]);
	i = 0;
	while (i < 12)
		mlx_destroy_image(s->mlx_ptr, s->ghost[i++]);
}

int close_window(t_solong *s)
{
	free_tab(s->map);
	destroy_all(s);
   	mlx_loop_end(s->mlx_ptr);
	mlx_clear_window(s->mlx_ptr, s->mlx_win);
	mlx_destroy_window(s->mlx_ptr, s->mlx_win);
	mlx_destroy_display(s->mlx_ptr);
	free(s->mlx_ptr);
    exit(0);
	return (0);
}