/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:50:56 by sebferna          #+#    #+#             */
/*   Updated: 2024/01/24 13:04:10 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
//get_next_line_utils.c
size_t	ft_strlen(const char *str);
int		ft_strchr(const char *str, int len);
char	*ft_strjoin(char *str1, char *str2);
void	*ft_calloc(size_t count, size_t size);
//get_next_line.c
char	*get_next_line(int fd);

#endif