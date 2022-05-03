/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepiney <llepiney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:27:48 by llepiney          #+#    #+#             */
/*   Updated: 2022/05/03 16:38:35 by llepiney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int	i;
	char	**map;

	i = 0;
	(void)argc;
	map = map_create(argv);
	if (!wall_valid(map))
	{
		printf("Error wall.\n");
		return (0);
	}
	if (!is_rect(map))
	{
		printf("Error rect.\n");
		return (0);
	}
	if (map == 0)
	{
		printf("Error map.\n");
		return (0);
	}
	while (map[i])
	{
		printf("line[%i] : %s\n", i, map[i]);
		i++;
	}
	return (0);
}