/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepiney <llepiney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 18:40:19 by llepiney          #+#    #+#             */
/*   Updated: 2022/05/05 23:16:47 by llepiney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	name_check(char *arg)
{
	int	i;
	int	len;

	len = ft_strlen2(arg);
	i = 0;
	if (arg[i] == '.' || arg[i] == '\0')
			return (0);
	while (i < len - 4)
	{
		arg++;
		i++;
	}
	if (!ft_strncmp(arg, ".ber", (len - 1)))
		return (1);
	return (0);
}

static int	count_line(char **argv)
{
	int		fd;
	int		i;
	char	*buf;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	buf = get_next_line(fd);
	while (buf != NULL)
	{
		free(buf);
		i++;
		buf = get_next_line(fd);
	}
	if (buf)
		free(buf);
	close(fd);
	return (i);
}

char	**map_create(char **argv)
{
	char	**map;
	int		i;
	int		fd;
	int		len;

	if (!name_check(argv[1]))
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1 || fd == 1)
		return (0);
	len = count_line(argv);
	map = malloc(sizeof(char *) * (len + 1));
	if (!map)
		return (NULL);
	i = 0;
	while (i < len)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}