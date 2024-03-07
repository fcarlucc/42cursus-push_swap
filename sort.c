/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarlucc <fcarlucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 22:35:29 by fla               #+#    #+#             */
/*   Updated: 2023/05/24 02:11:47 by fcarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_push(t_stack *stk, int len, int push)
{
	if (push == 0)
		pb(stk, 1);
	else
		pa(stk, 1);
	len--;
	return (len);
}

void	sort_3_a(t_stack *stk)
{
	if (stk->stack_a[0] < stk->stack_a[1] && stk->stack_a[0] < \
	stk->stack_a[2] && stk->stack_a[1] < stk->stack_a[2])
		return ;
	else if (stk->stack_a[0] < stk->stack_a[1] && stk->stack_a[0] < \
	stk->stack_a[2] && stk->stack_a[1] > stk->stack_a[2])
	{
		rra(stk, 1);
		sa(stk, 1);
	}
	else if (stk->stack_a[0] > stk->stack_a[1] && stk->stack_a[0] < \
	stk->stack_a[2] && stk->stack_a[1] < stk->stack_a[2])
		sa(stk, 1);
	else if (stk->stack_a[0] < stk->stack_a[1] && stk->stack_a[0] > \
	stk->stack_a[2] && stk->stack_a[1] > stk->stack_a[2])
		rra(stk, 1);
	else if (stk->stack_a[1] < stk->stack_a[2] && stk->stack_a[0] > \
	stk->stack_a[1] && stk->stack_a[0] > stk->stack_a[2])
		ra(stk, 1);
	else if (stk->stack_a[1] > stk->stack_a[2] && stk->stack_a[0] > \
	stk->stack_a[1] && stk->stack_a[0] > stk->stack_a[2])
	{
		ra(stk, 1);
		sa(stk, 1);
	}
}

int	sort_3_b(t_stack *stk, int len)
{
	if (len == 1)
		pa(stk, 1);
	else if (len == 2)
	{
		if (stk->stack_b[0] < stk->stack_b[1])
			sb(stk, 1);
		while (len--)
			pa(stk, 1);
	}
	else if (len == 3)
	{
		while (len || !(stk->stack_a[0] < stk->stack_a[1] \
		&& stk->stack_a[1] < stk->stack_a[2]))
		{
			if (len == 1 && stk->stack_a[0] > stk->stack_a[1])
				sa(stk, 1);
			else if (len == 1 || (len >= 2 && stk->stack_b[0] > stk->stack_b[1])
				|| (len == 3 && stk->stack_b[0] > stk->stack_b[2]))
				len = ft_push(stk, len, 1);
			else
				sb(stk, 1);
		}
	}
	return (0);
}

int	sort(t_stack *stk, int size)
{
	if (check_sorted(stk->stack_a, stk->la, 0) == 0)
	{
		if (size == 2)
			sa(stk, 1);
		else if (size == 3)
			sort_3_a(stk);
		else
			quicksort_a(stk, size, 0);
	}
	return (0);
}
