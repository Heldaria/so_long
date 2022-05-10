/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loan <loan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 18:40:19 by llepiney          #+#    #+#             */
/*   Updated: 2022/05/10 04:53:29 by loan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	init_value(t_solong *s)
{
	s->ccount = 0;
	s->ecount = 0;
	s->pcount = 0;
	s->item_count = 0;
	s->mvt = 0;
}

int	name_check(char *arg)
{
	int	i;
	int	len;

	len = ft_strlen2(arg);
	i = 0;
	if (!ft_strncmp(arg, ".ber", 4))
		return (0);
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
	if (fd == -1 || fd == 1)
		return (0);
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

	fd = open(argv[1], O_RDONLY);
	len = count_line(argv);
	if (fd == -1 || fd == 1 || len == 0)
		return (0);
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