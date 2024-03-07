/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarlucc <fcarlucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 22:35:29 by fla               #+#    #+#             */
/*   Updated: 2023/06/21 18:39:35 by fcarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	bubble_sort(int *stk_tmp, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (stk_tmp[i] > stk_tmp[j])
			{
				tmp = stk_tmp[i];
				stk_tmp[i] = stk_tmp[j];
				stk_tmp[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

static	int	find_pivot(int *pivot, int *stk, int size)
{
	int		*tmp_stk;
	int		i;

	tmp_stk = (int *)malloc(size * sizeof(int));
	if (!tmp_stk)
		return (0);
	i = 0;
	while (i < size)
	{
		tmp_stk[i] = stk[i];
		i++;
	}
	bubble_sort(tmp_stk, size);
	*pivot = tmp_stk[size / 2];
	free(tmp_stk);
	return (1);
}

static	void	quicksort_stacks(t_stack *stk, int len)
{
	if (len == 3 && stk->la == 3)
		sort_3_a(stk);
	else if (len == 2)
	{
		if (stk->stack_a[0] > stk->stack_a[1])
			sa(stk, 1);
	}
	else if (len == 3)
	{
		while (len != 3 || !(stk->stack_a[0] < stk->stack_a[1] \
		&& stk->stack_a[1] < stk->stack_a[2]))
		{
			if (len == 3 && stk->stack_a[0] > stk->stack_a[1] \
			&& stk->stack_a[2])
				sa(stk, 1);
			else if (len == 3 && !(stk->stack_a[2] > stk->stack_a[0]
					&& stk->stack_a[2] > stk->stack_a[1]))
				len = ft_push(stk, len, 0);
			else if (stk->stack_a[0] > stk->stack_a[1])
				sa(stk, 1);
			else if (len++)
				pa(stk, 1);
		}
	}
}

int	quicksort_a(t_stack *stk, int len, int n_rot)
{
	int	pivot;
	int	numbers;

	if (check_sorted(stk->stack_a, len, 0) == 1)
		return (1);
	numbers = len;
	if (len <= 3)
	{
		quicksort_stacks(stk, len);
		return (1);
	}
	if (!find_pivot(&pivot, stk->stack_a, len))
		return (0);
	while (len != numbers / 2 + numbers % 2)
	{
		if (stk->stack_a[0] < pivot && (len--))
			pb(stk, 1);
		else if (++n_rot)
			ra(stk, 1);
	}
	while (numbers / 2 + numbers % 2 != stk->la && n_rot--)
		rra(stk, 1);
	return (quicksort_a(stk, numbers / 2 + numbers % 2, 0)
		&& quicksort_b(stk, numbers / 2, 0));
	return (1);
}

int	quicksort_b(t_stack *stk, int len, int n_rot)
{
	int	pivot;
	int	numbers;

	if (check_sorted(stk->stack_b, len, 1) == 1)
		while (len--)
			pa(stk, 1);
	if (len <= 3)
	{
		sort_3_b(stk, len);
		return (1);
	}
	numbers = len;
	if (!find_pivot(&pivot, stk->stack_b, len))
		return (0);
	while (len != numbers / 2)
	{
		if (stk->stack_b[0] >= pivot && len--)
			pa(stk, 1);
		else if (++n_rot)
			rb(stk, 1);
	}
	while (numbers / 2 != stk->lb && n_rot--)
		rrb(stk, 1);
	return (quicksort_a(stk, numbers / 2 + numbers % 2, 0)
		&& quicksort_b(stk, numbers / 2, 0));
}
