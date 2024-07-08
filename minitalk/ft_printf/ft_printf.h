/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 11:44:16 by sebferna          #+#    #+#             */
/*   Updated: 2024/07/01 11:44:16 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>

void	ft_putstr(char *str, int *length);
void	ft_putchar(char c, int *length);
void	ft_puthexa(unsigned int n, int *length, char x);
void	ft_printptr(int ptr, int *length);
void	ft_printunsigned(unsigned int n, int *length);
int		ft_printf(char const *str, ...);
void	ft_putnbr(int nmb, int *length);

#endif
