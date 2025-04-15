/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:22:08 by ngaurama          #+#    #+#             */
/*   Updated: 2024/12/23 18:50:10 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	edge_case(int *stack, int size, int num)
{
	int	min_index;
	int	max_index;

	min_index = find_min_index(stack, size);
	max_index = find_max_index(stack, size);
	if (num <= stack[min_index] || num >= stack[max_index])
		return (min_index);
	return (-1);
}

int	find_target_in_a(int num, int *stack, int size)
{
	int	closest_index;
	int	closest_diff;
	int	diff;
	int	i;

	i = 0;
	if (edge_case(stack, size, num) > -1)
		return (edge_case(stack, size, num));
	closest_index = -1;
	closest_diff = INT_MAX;
	while (i < size)
	{
		if (stack[i] > num)
		{
			diff = stack[i] - num;
			if (diff < closest_diff)
			{
				closest_diff = diff;
				closest_index = i;
			}
		}
		i++;
	}
	return (closest_index);
}

int	calculate_cost(t_stacks *stacks, int index)
{
	int	cost_a;
	int	target_index;
	int	cost_b;

	if (index <= stacks->size_b / 2)
		cost_b = index;
	else
		cost_b = stacks->size_b - index;
	target_index = find_target_in_a(stacks->stack_b[index], stacks->stack_a,
			stacks->size_a);
	if (target_index <= stacks->size_a / 2)
		cost_a = target_index;
	else
		cost_a = stacks->size_a - target_index;
	if ((index <= stacks->size_b / 2) == (target_index <= stacks->size_a / 2))
	{
		if (cost_a > cost_b)
			return (cost_a);
		else
			return (cost_b);
	}
	else
		return (cost_a + cost_b);
}
