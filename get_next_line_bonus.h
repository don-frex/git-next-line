/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:41:55 by asaber            #+#    #+#             */
/*   Updated: 2022/11/23 16:05:51 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
int		ft_sln(char *str);
int		ft_strchr(char *str, char c);
char	*ft_strjoin(char *dest, char *src);
char	*ft_substr(char *str, int start, int end);
char	*ft_calloc(int count, int size);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

#endif