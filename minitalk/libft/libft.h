/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 11:44:16 by sebferna          #+#    #+#             */
/*   Updated: 2024/07/22 13:33:12 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <signal.h>
# include <limits.h>
# include <sys/types.h>

void	ft_putchar(int c);
void	ft_putnbr(int num);
int		ft_atoi(const char *str);

#endif
