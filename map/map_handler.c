/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepiney <llepiney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 18:40:19 by llepiney          #+#    #+#             */
/*   Updated: 2022/04/29 17:30:15 by llepiney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
	int	fd;
	int	i;
	char	*buf;

	i = 0;
	fd = open(argv[1], O_RDONLY, BUFFER_SIZE);
	while (!ft_strncmp(buf, "\0", ft_strlen(buf)))
	{
		if (i != 0)
			free(buf);
		buf = get_next_line(fd);
		i++;
	}
	free(buf);
	return (i);
}

char	**map_create(char **argv)
{
	char	**map;
	char	*buf;
	int		i;
	int		fd;

	if (!name_check(argv[1]))
		return (0);
	fd = open(argv[1], O_RDONLY, BUFFER_SIZE);
	if (fd == -1 || fd == 1)
		return (0);
	map = malloc(sizeof(char *) * (count_line(argv) + 1));
	if (!map)
		return (NULL);
	i = 0;
	while (!ft_strncmp(buf, "\0", ft_strlen(buf)))
	{
		if (i != 0)
			free(buf);
		buf = get_next_line(fd);
		map[i] = ft_strdup2(buf);
	}
	free(buf);
	map[i] = NULL;
	close(fd);
	return (map);
}