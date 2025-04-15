/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:38:47 by ngaurama          #+#    #+#             */
/*   Updated: 2024/12/23 18:23:37 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	init_stacks(int argc, t_stacks *stacks)
{
	(void)argc;
	stacks->size_b = 0;
	stacks->stack_b = safe_alloc(sizeof(int) * (stacks->size_a - 1));
	if (!stacks->stack_b)
		return (-1);
	return (0);
}

int	process_input_moves(t_stacks *stacks)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (execute_move(line, stacks) == -1)
			return (free(line), free_stacks(stacks), write_err(), 1);
		free(line);
		line = get_next_line(0);
	}
	return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	check_ok(t_stacks stacks)
{
	if (is_sorted(stacks.stack_a, stacks.size_a) && stacks.size_b == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
