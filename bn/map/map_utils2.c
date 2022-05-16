/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepiney <llepiney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:32:41 by llepiney          #+#    #+#             */
/*   Updated: 2022/05/16 18:37:13 by llepiney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	line_numb(char **map)
{
	int	size;

	size = 0;
	while (map[size])
		size++;
	return (size);
}

int	col_numb(char **map)
{
	int	size;

	size = 0;
	while (map[0][size])
		size++;
	return (size);
}
