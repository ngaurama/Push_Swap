/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 19:41:24 by ngaurama          #+#    #+#             */
/*   Updated: 2024/12/23 18:50:10 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	handle_multiple_args(int argc, char **argv, int **stack, int *size)
{
	*stack = ft_calloc((argc - 1), sizeof(int));
	if (!*stack)
		return (-1);
	if (main_helper(argc, argv, stack, size) == -1)
		return (-1);
	return (0);
}

int	parse_single_arg(char *arg, int **stack, int *size, int i)
{
	char	**numbers;
	int		count;
	char	*endptr;
	long	num;

	*size = 0;
	numbers = ft_split(arg, ' ');
	count = 0;
	while (numbers[count])
		count++;
	*stack = ft_calloc(count, sizeof(int));
	if (!*stack)
		return (free_sp(numbers), write_err(), 1);
	while (i < count)
	{
		if (!is_number(numbers[i]))
			return (free_sp(numbers), free(*stack), write_err(), 1);
		num = ft_strtol(numbers[i], &endptr);
		if (*endptr != '\0' || num < INT_MIN || num > INT_MAX)
			return (free_sp(numbers), free(*stack), write_err(), 1);
		(*stack)[i] = (int)num;
		i++;
	}
	*size = count;
	return (free_sp(numbers), 0);
}

int	process_token(char *token, int **stack_a, int *size_a, int argc)
{
	long	num;

	if (!is_number(token))
		return (-1);
	num = ft_strtol(token, NULL);
	if (num < INT_MIN || num > INT_MAX)
		return (-1);
	if (*size_a >= argc - 1)
		return (-1);
	(*stack_a)[(*size_a)++] = (int)num;
	return (0);
}

int	main_helper(int argc, char **argv, int **stack_a, int *size_a)
{
	int		i;
	char	*arg;
	char	*token;

	i = 1;
	while (i < argc)
	{
		arg = ft_strdup(argv[i]);
		if (!arg)
			return (-1);
		token = ft_strtok(arg, " ");
		while (token)
		{
			if (process_token(token, stack_a, size_a, argc) == -1)
				return (free(arg), write_err(), -1);
			token = ft_strtok(NULL, " ");
		}
		free(arg);
		i++;
	}
	return (0);
}
