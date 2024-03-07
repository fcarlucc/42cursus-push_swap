/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarlucc <fcarlucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:19:46 by fcarlucc          #+#    #+#             */
/*   Updated: 2023/06/08 14:03:14 by fcarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stk, int choice)
{
	int	tmp;
	int	i;

	i = 0;
	if (stk->la < 2)
		return ;
	tmp = stk->stack_a[0];
	while (i < stk->la - 1)
	{
		stk->stack_a[i] = stk->stack_a[i + 1];
		i++;
	}
	stk->stack_a[i] = tmp;
	if (choice == 1)
		write(1, "ra\n", 3);
}

void	rb(t_stack *stk, int choice)
{
	int	tmp;
	int	i;

	i = 0;
	if (stk->lb < 2)
		return ;
	tmp = stk->stack_b[0];
	while (i < stk->lb - 1)
	{
		stk->stack_b[i] = stk->stack_b[i + 1];
		i++;
	}
	stk->stack_b[i] = tmp;
	if (choice == 1)
		write(1, "rb\n", 3);
}

void	rr(t_stack *stk, int choice)
{
	ra(stk, 0);
	rb(stk, 0);
	if (choice == 1)
		write(1, "rr\n", 3);
}
