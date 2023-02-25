/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kabo <sel-kabo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 15:35:56 by sel-kabo          #+#    #+#             */
/*   Updated: 2023/02/15 16:56:36 by sel-kabo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_stock_line(char *str)
{
	int		i;
	char	*s;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	s = malloc(sizeof(char) * (i + 1));
	if (!s)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		s[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		s[i] = str[i];
		i++;
	}
	return (s[i] = '\0', s);
}

static char	*ft_new_str(char *str)
{
	int		i;
	int		j;
	char	*newstr;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	newstr = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!newstr)
	{
		free(str);
		return (NULL);
	}
	i++;
	j = 0;
	while (str[i])
		newstr[j++] = str[i++];
	newstr[j] = '\0';
	free(str);
	return (newstr);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (0);
	str[fd] = ft_read(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	line = ft_stock_line(str[fd]);
	str[fd] = ft_new_str(str[fd]);
	return (line);
}
