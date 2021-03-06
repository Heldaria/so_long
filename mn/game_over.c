/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepiney <llepiney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 22:53:02 by llepiney          #+#    #+#             */
/*   Updated: 2022/05/16 20:28:20 by llepiney         ###   ########.fr       */
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

static void	destroy_all(t_solong *s)
{
	mlx_destroy_image(s->mlx_ptr, s->wall);
	mlx_destroy_image(s->mlx_ptr, s->grass);
	mlx_destroy_image(s->mlx_ptr, s->hole);
	mlx_destroy_image(s->mlx_ptr, s->chkn);
	mlx_destroy_image(s->mlx_ptr, s->buck[0]);
	mlx_destroy_image(s->mlx_ptr, s->buck[3]);
	mlx_destroy_image(s->mlx_ptr, s->buck[6]);
	mlx_destroy_image(s->mlx_ptr, s->buck[9]);
}

int	close_window(t_solong *s)
{
	free_tab(s->map);
	destroy_all(s);
	mlx_loop_end(s->mlx_ptr);
	mlx_clear_window(s->mlx_ptr, s->mlx_win);
	mlx_destroy_window(s->mlx_ptr, s->mlx_win);
	mlx_destroy_display(s->mlx_ptr);
	free(s->mlx_ptr);
	exit(0);
}
