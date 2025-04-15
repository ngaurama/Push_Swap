/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 18:13:26 by ngaurama          #+#    #+#             */
/*   Updated: 2024/12/23 18:50:10 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(int **stack_a, int *size_a)
{
	if (is_sorted(*stack_a, *size_a))
		return ;
	if ((*stack_a)[0] > (*stack_a)[1] && (*stack_a)[0] > (*stack_a)[2])
	{
		rotate_a(stack_a, *size_a);
		print_operation("ra");
	}
	else if ((*stack_a)[1] > (*stack_a)[2] && (*stack_a)[1] > (*stack_a)[0])
	{
		rev_rotate_a(stack_a, *size_a);
		print_operation("rra");
	}
	if ((*stack_a)[0] > (*stack_a)[1])
	{
		swap_a(stack_a, *size_a);
		print_operation("sa");
	}
}

void	sort_below_three(int **stack_a, int *size_a)
{
	if (*size_a == 1)
		return ;
	if (*size_a == 2)
	{
		if ((*stack_a)[0] > (*stack_a)[1])
		{
			swap_a(stack_a, *size_a);
			print_operation("sa");
		}
		return ;
	}
}

void	sort_stack(t_stacks stacks, int size)
{
	int	i;
	int	cheapest_cost;

	i = 0;
	cheapest_cost = 0;
	stacks.size_a = size;
	stacks.size_b = 0;
	if (stacks.size_a <= 2)
	{
		sort_below_three(&stacks.stack_a, &stacks.size_a);
		return ;
	}
	stacks.stack_b = (int *)safe_alloc(sizeof(int) * size);
	push_to_b(&stacks, i);
	sort_three(&stacks.stack_a, &stacks.size_a);
	push_back_to_a(&stacks, i, cheapest_cost);
	if (!is_sorted(stacks.stack_a, stacks.size_a))
		shift_till_sorted(&stacks.stack_a, &stacks.size_a);
	free(stacks.stack_b);
}
