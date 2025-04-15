/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_op_simul_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:40:42 by ngaurama          #+#    #+#             */
/*   Updated: 2024/12/17 23:39:13 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rr(int *stack_a, int size_a, int *stack_b, int size_b)
{
	ra(&stack_a, size_a);
	rb(&stack_b, size_b);
}

void	rrr(int *stack_a, int size_a, int *stack_b, int size_b)
{
	rra(&stack_a, size_a);
	rrb(&stack_b, size_b);
}

void	ss(int *stack_a, int size_a, int *stack_b, int size_b)
{
	sa(&stack_a, size_a);
	sb(&stack_b, size_b);
}
