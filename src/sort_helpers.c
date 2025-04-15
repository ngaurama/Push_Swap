/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 23:05:03 by ngaurama          #+#    #+#             */
/*   Updated: 2024/12/23 18:50:10 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	shift_till_sorted(int **stack_a, int *size_a)
{
	int	min_index;

	min_index = find_min_index(*stack_a, *size_a);
	if (min_index > *size_a / 2)
	{
		while (min_index < *size_a)
		{
			rev_rotate_a(stack_a, *size_a);
			print_operation("rra");
			min_index++;
		}
	}
	else
	{
		while (min_index > 0)
		{
			rotate_a(stack_a, *size_a);
			print_operation("ra");
			min_index--;
		}
	}
}

void	push_back_to_a(t_stacks *stacks, int i, int cheapest_cost)
{
	int	cheapest_index;
	int	target_in_a;
	int	cost;

	while (stacks->size_b > 0)
	{
		cheapest_index = 0;
		i = 1;
		cheapest_cost = calculate_cost(stacks, 0);
		while (i < stacks->size_b)
		{
			cost = calculate_cost(stacks, i);
			if (cost < cheapest_cost)
			{
				cheapest_cost = cost;
				cheapest_index = i;
			}
			i++;
		}
		target_in_a = find_target_in_a(stacks->stack_b[cheapest_index],
				stacks->stack_a, stacks->size_a);
		rotation_logic(stacks, cheapest_index, target_in_a);
		push_a(&stacks->stack_a, &stacks->stack_b, &stacks->size_a,
			&stacks->size_b);
	}
}

void	push_to_b(t_stacks *stacks, int i)
{
	int	pushed;
	int	size;

	pushed = 0;
	size = stacks->size_a;
	while (size > 6 && i++ < size && pushed < size / 2)
	{
		if ((stacks->stack_a[0] + 1) <= size / 2)
		{
			push_b(&stacks->stack_a, &stacks->stack_b, &stacks->size_a,
				&stacks->size_b);
			pushed++;
		}
		else
		{
			rotate_a(&stacks->stack_a, stacks->size_a);
			print_operation("ra");
		}
	}
	while (size - pushed > 3)
	{
		push_b(&stacks->stack_a, &stacks->stack_b, &stacks->size_a,
			&stacks->size_b);
		pushed++;
	}
}

int	find_min_index(int *stack, int size)
{
	int	i;
	int	min_index;

	min_index = 0;
	i = 1;
	while (i < size)
	{
		if (stack[i] < stack[min_index])
			min_index = i;
		i++;
	}
	return (min_index);
}

int	find_max_index(int *stack, int size)
{
	int	i;
	int	max_index;

	i = 1;
	max_index = 0;
	while (i < size)
	{
		if (stack[i] > stack[max_index])
			max_index = i;
		i++;
	}
	return (max_index);
}
