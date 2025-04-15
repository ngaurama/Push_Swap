/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:00:24 by ngaurama          #+#    #+#             */
/*   Updated: 2024/12/23 18:50:10 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(t_Element *elements, int size_a)
{
	int			i;
	int			j;
	t_Element	temp;

	i = 0;
	while (i < size_a - 1)
	{
		j = 0;
		while (j < size_a - 1 - i)
		{
			if (elements[j].value > elements[j + 1].value)
			{
				temp = elements[j];
				elements[j] = elements[j + 1];
				elements[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

int	*new_stack(int *stack_a, int size_a)
{
	int			*stack;
	int			i;
	t_Element	*elements;

	i = 0;
	elements = (t_Element *)safe_alloc(sizeof(t_Element) * size_a);
	while (i < size_a)
	{
		elements[i].value = stack_a[i];
		elements[i].index = i;
		i++;
	}
	bubble_sort(elements, size_a);
	stack = (int *)safe_alloc(sizeof(int) * size_a);
	i = 0;
	while (i < size_a)
	{
		stack[elements[i].index] = i;
		i++;
	}
	free(elements);
	return (stack);
}
