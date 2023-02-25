/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kabo <sel-kabo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:01:26 by sel-kabo          #+#    #+#             */
/*   Updated: 2023/02/15 16:56:02 by sel-kabo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

static size_t	len_str_buff(char *str, char *buff)
{
	size_t		len_str_buff;

	len_str_buff = (ft_strlen(str) + ft_strlen(buff));
	return (len_str_buff);
}

static char	*ft_strjoin(char *str, char *buff)
{
	size_t		i;
	size_t		j;
	char		*newstr;

	if (!str)
	{
		str = malloc(1 * sizeof(char));
		str[0] = '\0';
	}
	else if (!str)
		return (NULL);
	newstr = malloc(sizeof(char) * (len_str_buff(str, buff) + 1));
	if (newstr == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
			newstr[i] = str[i];
			i++;
	}
	while (buff[j] != '\0')
		newstr[i++] = buff[j++];
	newstr[len_str_buff(str, buff)] = '\0';
	return (free(str), newstr);
}

static char	*ft_strchr(const char *s, unsigned char c)
{
	while (*s != '\0' && c != *s)
		s++;
	if (c == *s)
		return ((char *)s);
	return (0);
}

char	*ft_read(int fd, char *str)
{
	char	*buff;
	int		n;
	int		is_nw;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	n = 1;
	is_nw = 0;
	while (n != 0 && is_nw == 0)
	{
		n = read(fd, buff, BUFFER_SIZE);
		if (n == -1)
		{
			if (str != NULL)
				free(str);
			return (free(buff), NULL);
		}
		buff[n] = '\0';
		str = ft_strjoin(str, buff);
		if (ft_strchr(str, '\n'))
			is_nw = 1;
	}
	return (free(buff), str);
}
