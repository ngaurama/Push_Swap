/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:30:04 by ngaurama          #+#    #+#             */
/*   Updated: 2024/12/17 23:30:22 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	int			*stack;
	int			size;

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
	stacks.stack_a = stack;
	stacks.size_a = size;
	init_stacks(argc, &stacks);
	if (process_input_moves(&stacks) == 1)
		return (1);
	return (check_ok(stacks), free_stacks(&stacks), 0);
}
