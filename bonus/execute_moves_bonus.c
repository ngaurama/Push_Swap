/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_moves_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 23:30:06 by ngaurama          #+#    #+#             */
/*   Updated: 2024/12/23 18:00:37 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	simul_move(char *move, t_stacks *stacks)
{
	if (!ft_strcmp(move, "ss\n"))
		ss(stacks->stack_a, stacks->size_a, stacks->stack_b, stacks->size_b);
	else if (!ft_strcmp(move, "rr\n"))
		rr(stacks->stack_a, stacks->size_a, stacks->stack_b, stacks->size_b);
	else if (!ft_strcmp(move, "rrr\n"))
		rrr(stacks->stack_a, stacks->size_a, stacks->stack_b, stacks->size_b);
}

int	execute_move(char *move, t_stacks *stacks)
{
	if (!ft_strcmp(move, "sa\n"))
		sa(&stacks->stack_a, stacks->size_a);
	else if (!ft_strcmp(move, "sb\n"))
		sb(&stacks->stack_b, stacks->size_b);
	else if (!ft_strcmp(move, "ra\n"))
		ra(&stacks->stack_a, stacks->size_a);
	else if (!ft_strcmp(move, "rb\n"))
		rb(&stacks->stack_b, stacks->size_b);
	else if (!ft_strcmp(move, "rra\n"))
		rra(&stacks->stack_a, stacks->size_a);
	else if (!ft_strcmp(move, "rrb\n"))
		rrb(&stacks->stack_b, stacks->size_b);
	else if (!ft_strcmp(move, "pa\n"))
		pa(&stacks->stack_a, &stacks->stack_b, &stacks->size_a,
			&stacks->size_b);
	else if (!ft_strcmp(move, "pb\n"))
		pb(&stacks->stack_a, &stacks->stack_b, &stacks->size_a,
			&stacks->size_b);
	else if (!ft_strcmp(move, "ss\n") || !ft_strcmp(move, "rr\n")
		|| !ft_strcmp(move, "rrr\n"))
		simul_move(move, stacks);
	else
		return (-1);
	return (0);
}
