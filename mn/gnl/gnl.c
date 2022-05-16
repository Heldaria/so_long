/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepiney <llepiney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 16:47:29 by llepiney          #+#    #+#             */
/*   Updated: 2022/05/16 20:24:36 by llepiney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_free(char *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}

char	*get_next_line(int fd)
{
	static char	*to_read = NULL;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (read(fd, buffer, 0) < 0)
	{
		free(buffer);
		return (NULL);
	}
	if (!to_read)
		to_read = ft_strdup("");
	if (ft_read(fd, &to_read, &buffer, &line) == 0 && *line == '\0')
	{
		ft_free(line);
		return (NULL);
	}
	return (line);
}

int	ft_read(int fd, char **to_read, char **buffer, char **line)
{
	char	*temp;
	int		count;

	count = 1;
	while (!ft_strchr(*to_read, '\n') && count)
	{
		count = read(fd, *buffer, BUFFER_SIZE);
		temp = *to_read;
		(*buffer)[count] = '\0';
		*to_read = ft_strjoin(*to_read, *buffer);
		ft_free(temp);
	}
	ft_free(*buffer);
	ft_line(line, to_read);
	return (count);
}

char	*ft_line(char **line, char **to_read)
{
	int		jump;
	char	*temp;

	jump = 0;
	temp = *to_read;
	while ((*to_read)[jump] != '\n' && (*to_read)[jump] != '\0')
		jump++;
	if (ft_strchr(*to_read, '\n'))
	{
		*line = ft_substr(*to_read, 0, jump + 1);
		*to_read = ft_strdup(*to_read + jump + 1);
	}
	else
	{
		*line = ft_strdup(temp);
		*to_read = NULL;
	}
	ft_free(temp);
	return (*line);
}
