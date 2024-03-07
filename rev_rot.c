/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarlucc <fcarlucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 03:46:23 by fcarlucc          #+#    #+#             */
/*   Updated: 2023/06/08 14:03:03 by fcarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stk, int choice)
{
	int	tmp;
	int	i;

	i = stk->la - 1;
	tmp = stk->stack_a[i];
	while (i > 0)
	{
		stk->stack_a[i] = stk->stack_a[i - 1];
		i--;
	}
	stk->stack_a[0] = tmp;
	if (choice == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_stack *stk, int choice)
{
	int	tmp;
	int	i;

	i = stk->lb - 1;
	tmp = stk->stack_b[i];
	while (i > 0)
	{
		stk->stack_b[i] = stk->stack_b[i - 1];
		i--;
	}
	stk->stack_b[0] = tmp;
	if (choice == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack *stk, int choice)
{
	rra(stk, 0);
	rrb(stk, 0);
	if (choice == 1)
		write(1, "rrr\n", 4);
}
