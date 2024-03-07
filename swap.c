/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarlucc <fcarlucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 03:44:03 by fcarlucc          #+#    #+#             */
/*   Updated: 2023/06/08 14:03:24 by fcarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stk, int choice)
{
	int	tmp;

	if (stk->la < 2)
		return ;
	tmp = stk->stack_a[0];
	stk->stack_a[0] = stk->stack_a[1];
	stk->stack_a[1] = tmp;
	if (choice == 1)
		write(1, "sa\n", 3);
}

void	sb(t_stack *stk, int choice)
{
	int	tmp;

	if (stk->lb < 2)
		return ;
	tmp = stk->stack_b[1];
	stk->stack_b[1] = stk->stack_b[0];
	stk->stack_b[0] = tmp;
	if (choice == 1)
		write(1, "sb\n", 3);
}

void	ss(t_stack *stk, int choice)
{
	sa(stk, 0);
	sb(stk, 0);
	if (choice == 1)
		write(1, "ss\n", 3);
}
