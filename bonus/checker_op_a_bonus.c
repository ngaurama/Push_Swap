/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_op_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:38:44 by ngaurama          #+#    #+#             */
/*   Updated: 2024/12/12 16:45:50 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ra(int **stack, int size)
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

void	rra(int **stack, int size)
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

void	sa(int **stack, int size)
{
	int	temp;

	if (size > 1)
	{
		temp = (*stack)[0];
		(*stack)[0] = (*stack)[1];
		(*stack)[1] = temp;
	}
}

void	pa(int **stack_a, int **stack_b, int *size_a, int *size_b)
{
	int	i;

	i = *size_a;
	if (*size_b > 0)
	{
		while (i > 0)
		{
			(*stack_a)[i] = (*stack_a)[i - 1];
			i--;
		}
		(*stack_a)[0] = (*stack_b)[0];
		(*size_a)++;
		i = 0;
		while (i < *size_b - 1)
		{
			(*stack_b)[i] = (*stack_b)[i + 1];
			i++;
		}
		(*size_b)--;
	}
}
