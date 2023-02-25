/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-kabo <sel-kabo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:01:16 by sel-kabo          #+#    #+#             */
/*   Updated: 2023/02/12 15:48:51 by sel-kabo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <libc.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 999
# endif

char	*get_next_line(int fd);
size_t	ft_strlen(char *s);
char	*ft_read(int fd, char *str);
size_t	ft_strlen(char *s);

#endif