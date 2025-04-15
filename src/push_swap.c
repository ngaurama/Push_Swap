/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 20:28:46 by ngaurama          #+#    #+#             */
/*   Updated: 2024/12/17 23:49:01 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int			*stack;
	int			size;
	t_stacks	stacks;

	stack = NULL;
	size = 0;
	if (argc <= 1)
		return (0);
	if (!check_empty_input(argv))
		return (write_err(), 1);
	if (argc == 2)
	{
		if (parse_single_arg(argv[1], &stack, &size, 0))
			return (0);
	}
	else if (handle_multiple_args(argc, argv, &stack, &size) == -1)
		return (free(stack), 1);
	if (has_duplicates(stack, size))
		return (write_err(), free(stack), 1);
	if (is_sorted(stack, size))
		return (free(stack), 1);
	stacks.stack_a = new_stack(stack, size);
	return (sort_stack(stacks, size), free(stacks.stack_a), free(stack), 0);
}
