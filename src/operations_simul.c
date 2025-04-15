/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_simul.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:28:25 by ngaurama          #+#    #+#             */
/*   Updated: 2024/12/23 18:50:10 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_operation(char *operation)
{
	ft_printf("%s\n", operation);
}

void	simultaneous_rotate(int *stack_a, int size_a, int *stack_b, int size_b)
{
	rotate_a(&stack_a, size_a);
	rotate_b(&stack_b, size_b);
	print_operation("rr");
}

void	simultaneous_reverse_rotate(int *stack_a, int size_a, int *stack_b,
		int size_b)
{
	rev_rotate_a(&stack_a, size_a);
	rev_rotate_b(&stack_b, size_b);
	print_operation("rrr");
}
