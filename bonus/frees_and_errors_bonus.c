/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees_and_errors_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 23:27:30 by ngaurama          #+#    #+#             */
/*   Updated: 2024/12/18 00:08:57 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	free_stacks(t_stacks *stacks)
{
	if (stacks->stack_a)
		free(stacks->stack_a);
	if (stacks->stack_b)
		free(stacks->stack_b);
}
