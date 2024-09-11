/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:35:31 by sebferna          #+#    #+#             */
/*   Updated: 2024/09/11 11:11:51 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	int	*sa;
	int	*sb;
	int	*sp;
	int	sia;
	int	sib;
	int	argc;
	int	error;
	int	atoierror;
	int	jatoi;
}	t_list;

char	*ft_substr(char *s, int start, int len);
char	*get_next_line(int fd);
int		checker_bonus(int argc, char **argv);
int		ft_strlen(char *s);
int		ft_atoi(const char *str, t_list *d);
int		check_same_nums(t_list *d);
int		check_args(char **argv, int argc);
int		check_num(char *s);
void	ss(t_list *d);
void	sa(int *sa);
void	rra(t_list *d);
void	rrb(t_list *d);
void	ra(t_list *d);
void	pa(t_list *d);
void	pb(t_list *d);
void	rb(t_list *d);
void	rr(t_list *d);
void	rrr(t_list *d);
void	sb(int *sb);
void	swap(int *argv1, int *argv2);
void	ft_free(t_list *d, int print);
void	ft_checker_lines(t_list *d);
#endif