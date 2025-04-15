/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 21:27:39 by ngaurama          #+#    #+#             */
/*   Updated: 2024/12/23 18:50:10 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	non_simul_rotate_a(t_stacks *stacks, int target_a, int rot_a)
{
	while (rot_a-- > 0)
	{
		if (target_a <= stacks->size_a / 2)
		{
			rotate_a(&stacks->stack_a, stacks->size_a);
			print_operation("ra");
		}
		else
		{
			rev_rotate_a(&stacks->stack_a, stacks->size_a);
			print_operation("rra");
		}
	}
}

void	non_simul_rotate_b(t_stacks *stacks, int cheapest_in_b, int rot_b)
{
	while (rot_b-- > 0)
	{
		if (cheapest_in_b <= stacks->size_b / 2)
		{
			rotate_b(&stacks->stack_b, stacks->size_b);
			print_operation("rb");
		}
		else
		{
			rev_rotate_b(&stacks->stack_b, stacks->size_b);
			print_operation("rrb");
		}
	}
}

t_rot	simul(t_stacks *stacks, int cheapest_in_b, int target_a, t_rot *rotate)
{
	t_rot	rots;

	rots = *rotate;
	while (rots.rot_a > 0 && rots.rot_b > 0)
	{
		if (cheapest_in_b <= stacks->size_b / 2 && target_a <= stacks->size_a
			/ 2)
			simultaneous_rotate(stacks->stack_a, stacks->size_a,
				stacks->stack_b, stacks->size_b);
		else if (cheapest_in_b > stacks->size_b / 2 && target_a > stacks->size_a
			/ 2)
			simultaneous_reverse_rotate(stacks->stack_a, stacks->size_a,
				stacks->stack_b, stacks->size_b);
		rots.rot_a--;
		rots.rot_b--;
	}
	return (rots);
}

void	rotation_logic(t_stacks *stacks, int cheapest_in_b, int target_a)
{
	t_rot	rotate;

	if ((target_a <= stacks->size_a / 2))
		rotate.rot_a = target_a;
	else
		rotate.rot_a = stacks->size_a - target_a;
	if ((cheapest_in_b <= stacks->size_b / 2))
		rotate.rot_b = cheapest_in_b;
	else
		rotate.rot_b = stacks->size_b - cheapest_in_b;
	if ((cheapest_in_b <= stacks->size_b / 2 && target_a <= stacks->size_a / 2)
		|| (cheapest_in_b > stacks->size_b / 2 && target_a > stacks->size_a
			/ 2))
		rotate = simul(stacks, cheapest_in_b, target_a, &rotate);
	non_simul_rotate_a(stacks, target_a, rotate.rot_a);
	non_simul_rotate_b(stacks, cheapest_in_b, rotate.rot_b);
}
