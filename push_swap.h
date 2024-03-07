/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarlucc <fcarlucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 21:47:06 by fcarlucc          #+#    #+#             */
/*   Updated: 2023/06/21 18:47:24 by fcarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_stack
{
	int	*stack_a;
	int	*stack_b;	
	int	la;
	int	lb;
}		t_stack;

void	pa(t_stack *stk, int choice);
void	pb(t_stack *stk, int choice);
void	sa(t_stack *stk, int choice);
void	sb(t_stack *stk, int choice);
void	ss(t_stack *stk, int choice);
void	ra(t_stack *stk, int choice);
void	rb(t_stack *stk, int choice);
void	rr(t_stack *stk, int choice);
void	rra(t_stack *stk, int choice);
void	rrb(t_stack *stk, int choice);
void	rrr(t_stack *stk, int choice);
char	**ft_split(const char *s, char c);
int		ft_strcmp(char *s1, char *s2);
char	*get_next_line(int fd);
void	free_matrix(char **av);
void	ft_error(int *stack);
int		len_stack(char **av);
void	check_doubles(int *stack, int size);
int		push_swap_atoi(char *str, int *stack);
void	fill_stack(char **av);
int		ft_push(t_stack *stk, int len, int push);
int		sort(t_stack *stk, int size);
void	sort_3_a(t_stack *stk);
int		sort_3_b(t_stack *stk, int len);
int		quicksort_a(t_stack *stk, int len, int n_rot);
int		quicksort_b(t_stack *stk, int len, int n_rot);
int		check_sorted(int *stack, int size, int sequence);

#endif
