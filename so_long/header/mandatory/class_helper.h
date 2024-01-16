/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class_helper.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dong-kim <dong-kim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 20:01:50 by dong-kim          #+#    #+#             */
/*   Updated: 2023/07/07 22:57:38 by dong-kim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_HELPER_H
# define CLASS_HELPER_H

# include <libft.h>

/* LIBFT ARCHIVE */
// BITMASK
int		ft_is_bit_set_7(char variable, int bit_position);

// DISPLAY
void	ft_putstr(char *str);
void	ft_putendl_fd(char *s, int fd);

// MEMORY
void	*ft_memset(void *str, int c, size_t n);

// STRING
size_t	ft_strlen(const char *str);
char	**ft_split(char const *s, char c);
int		ft_strcmp(const char *string1, const char *string2);

// IMPLEMENTATION -> FT_PRINTF
int		ft_printf(const char *format, ...);

// DATA STRUCTURE -> QUEUE
void	enqueue(struct s_queue *queue, void *data);
void	*dequeue(struct s_queue *queue);
int		is_empty(struct s_queue *queue);

#endif
