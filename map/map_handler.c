/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepiney <llepiney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 18:40:19 by llepiney          #+#    #+#             */
/*   Updated: 2022/04/28 19:00:36 by llepiney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	name_check(char *name)
{
	int	i;
	int	len;

	len = ft_strlen(name);
	i = len - 3;
	while (i <= len)
	{
		
	}
}

char	**map_handler(char **argv)
{

}