/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dong-kim <dong-kim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 18:50:11 by dong-kim          #+#    #+#             */
/*   Updated: 2023/06/26 04:02:30 by dong-kim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef ULIMIT_N
#  define ULIMIT_N 49152
# endif

int		found_newline(char *buffer);
char	*get_next_line(int fd);
char	*ft_strjoin(char *data_line, char *buffer);
char	*concat(char *str, char *data_line, int *idx);
char	*solve(int fd, char *buffer, char *next_line, int rd_bytes);
size_t	find_size(char *data_line);
size_t	ft_strlen_gnl(const char *str);

#endif