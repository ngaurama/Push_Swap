/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 18:53:49 by ngaurama          #+#    #+#             */
/*   Updated: 2024/12/23 18:50:10 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_b(int **stack, int size)
{
	int	i;
	int	temp;

	i = 0;
	if (size > 1)
	{
		temp = (*stack)[0];
		while (i < size - 1)
		{
			(*stack)[i] = (*stack)[i + 1];
			i++;
		}
		(*stack)[size - 1] = temp;
	}
}

void	rev_rotate_b(int **stack, int size)
{
	int	i;
	int	temp;

	i = 0;
	if (size > 1)
	{
		temp = (*stack)[size - 1];
		i = size - 1;
		while (i > 0)
		{
			(*stack)[i] = (*stack)[i - 1];
			i--;
		}
		(*stack)[0] = temp;
	}
}

void	swap_b(int **stack, int size)
{
	int	temp;

	if (size > 1)
	{
		temp = (*stack)[0];
		(*stack)[0] = (*stack)[1];
		(*stack)[1] = temp;
	}
}

void	push_b(int **stack_a, int **stack_b, int *size_a, int *size_b)
{
	int	i;

	i = *size_b;
	if (*size_a > 0)
	{
		while (i > 0)
		{
			(*stack_b)[i] = (*stack_b)[i - 1];
			i--;
		}
		(*stack_b)[0] = (*stack_a)[0];
		(*size_b)++;
		i = 0;
		while (i < *size_a - 1)
		{
			(*stack_a)[i] = (*stack_a)[i + 1];
			i++;
		}
		(*size_a)--;
		print_operation("pb");
	}
}
