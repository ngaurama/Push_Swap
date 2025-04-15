/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:29:29 by ngaurama          #+#    #+#             */
/*   Updated: 2024/12/23 18:50:10 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*safe_alloc(size_t bytes)
{
	void	*ret;

	ret = malloc(bytes);
	if (ret == NULL)
		error_exit("Error with memory allocation");
	return (ret);
}

int	has_duplicates(int *array, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] == array[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_sorted(int *arr, int size)
{
	int	i;
	int	is_sorted;

	i = 0;
	is_sorted = 1;
	while (i < size - 1)
	{
		if (arr[i] > arr[i + 1])
		{
			is_sorted = 0;
			break ;
		}
		i++;
	}
	return (is_sorted);
}

int	is_number(char *str)
{
	if (!str || *str == '\0')
		return (0);
	if (*str == '-' || *str == '+')
		str++;
	if (!ft_isdigit(*str))
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	check_empty_input(char **argv)
{
	int	i;

	i = 0;
	if (!argv[1][i])
		return (0);
	while (argv[1][i] == ' ')
		i++;
	if (argv[1][i] == '\0')
		return (0);
	return (1);
}
