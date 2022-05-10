/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepiney <llepiney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 01:41:29 by llepiney          #+#    #+#             */
/*   Updated: 2022/05/11 01:48:13 by llepiney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strjoin2(char *s1, char *s2)
{
	char	*ret;
	int		i;
	int		j;
	int		len;

	len = (ft_strlen(s1) + ft_strlen(s2) + 1);
	i = 0;
	j = 0;
	ret = malloc(sizeof(char) * len);
	if (!ret)
		return (0);
	if (!s1 || !s2)
		return (0);
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		ret[i + j] = s2[j];
		j++;
	}
	ret[i + j] = '\0';
	return (ret);
}
