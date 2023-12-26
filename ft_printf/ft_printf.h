/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:35:50 by sebferna          #+#    #+#             */
/*   Updated: 2023/12/26 13:19:54 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

//PRINTCHAR
int	ft_putstr(const char *s);
int	ft_putchar(char s);
//PRINTNUMBERS
int	ft_putnbr(long int nbr);
int	ft_printunsigned(unsigned long long int nbr);
int	ft_printhexa(unsigned long nbr, char c);
int	ft_printptr(unsigned long nbr);
//PRINTF
int	ft_printf(char const *s, ...);

#endif