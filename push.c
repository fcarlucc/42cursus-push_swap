/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarlucc <fcarlucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 03:42:38 by fcarlucc          #+#    #+#             */
/*   Updated: 2023/06/08 14:02:46 by fcarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *stk, int choice)
{
	int	i;

	if (!stk->stack_b)
		return ;
	stk->la++;
	i = stk->la - 1;
	while (i > 0)
	{
		stk->stack_a[i] = stk->stack_a[i - 1];
		i--;
	}
	stk->stack_a[0] = stk->stack_b[0];
	i = 0;
	while (i < stk->lb - 1)
	{
		stk->stack_b[i] = stk->stack_b[i + 1];
		i++;
	}
	stk->lb--;
	if (choice == 1)
		write(1, "pa\n", 3);
}

void	pb(t_stack *stk, int choice)
{
	int	i;

	if (!stk->stack_a)
		return ;
	stk->lb++;
	i = stk->lb - 1;
	while (i > 0)
	{
		stk->stack_b[i] = stk->stack_b[i - 1];
		i--;
	}
	stk->stack_b[0] = stk->stack_a[0];
	i = 0;
	while (i < stk->la - 1)
	{
		stk->stack_a[i] = stk->stack_a[i + 1];
		i++;
	}
	stk->la--;
	if (choice == 1)
		write(1, "pb\n", 3);
}
