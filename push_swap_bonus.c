/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarlucc <fcarlucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 02:01:18 by fcarlucc          #+#    #+#             */
/*   Updated: 2023/06/21 18:22:03 by fcarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	error(t_stack *stk)
{
	free(stk->stack_a);
	free(stk->stack_b);
	write(2, "error\n", 6);
	exit(1);
}

static void	read_moves(t_stack *stk, char *moves)
{
	if (ft_strcmp(moves, "pa\n"))
		pa(stk, 0);
	else if (ft_strcmp(moves, "pb\n"))
		pb(stk, 0);
	else if (ft_strcmp(moves, "sa\n"))
		sa(stk, 0);
	else if (ft_strcmp(moves, "sb\n"))
		sb(stk, 0);
	else if (ft_strcmp(moves, "ss\n"))
		ss(stk, 0);
	else if (ft_strcmp(moves, "ra\n"))
		ra(stk, 0);
	else if (ft_strcmp(moves, "rb\n"))
		rb(stk, 0);
	else if (ft_strcmp(moves, "rr\n"))
		rr(stk, 0);
	else if (ft_strcmp(moves, "rra\n"))
		rra(stk, 0);
	else if (ft_strcmp(moves, "rrb\n"))
		rrb(stk, 0);
	else if (ft_strcmp(moves, "rrr\n"))
		rrr(stk, 0);
	else
		error(stk);
}

static void	check_moves(t_stack *stk)
{
	char		*move;

	move = get_next_line(0);
	while (move)
	{
		read_moves(stk, move);
		free(move);
		move = get_next_line(0);
	}
	if (check_sorted(stk->stack_a, stk->la, 0) && stk->lb == 0)
		write(1, "OK\n", 3);
	else
		write(1, "K0\n", 3);
	if (stk->stack_a)
		free(stk->stack_a);
	if (stk->stack_b)
		free(stk->stack_b);
}

static void	fill_checker(char **av, t_stack *stk)
{
	int		size;
	int		i;

	i = -1;
	size = len_stack(av);
	stk->stack_a = malloc(size * sizeof(int));
	if (!stk->stack_a)
		return ;
	stk->la = size;
	stk->stack_b = malloc(size * sizeof(int));
	if (!stk->stack_b)
	{
		free(stk->stack_a);
		return ;
	}
	stk->lb = 0;
	while (++i < size)
		stk->stack_a[i] = push_swap_atoi(av[i], stk->stack_a);
	check_doubles(stk->stack_a, size);
}

int	main(int ac, char **av)
{
	t_stack	stk;

	if (ac > 1)
	{
		av++;
		if (ac == 2)
			av = ft_split(*av, ' ');
		fill_checker(av, &stk);
		if (ac == 2)
			free_matrix(av);
		check_moves(&stk);
		return (0);
	}
	return (0);
}
