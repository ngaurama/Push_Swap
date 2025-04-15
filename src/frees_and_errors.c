/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees_and_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 22:58:48 by ngaurama          #+#    #+#             */
/*   Updated: 2024/12/23 18:50:10 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_sp(char **split_array)
{
	int	i;

	i = 0;
	if (!split_array)
		return ;
	while (split_array[i])
	{
		free(split_array[i]);
		i++;
	}
	free(split_array);
}

int	free_err(char *arg, int *stack_a)
{
	if (arg)
		free(arg);
	if (stack_a)
		free(stack_a);
	write_err();
	return (-1);
}

void	write_err(void)
{
	char	*str;
	int		len;

	str = "Error\n";
	len = ft_strlen(str);
	write(STDERR_FILENO, str, len);
}

void	error_exit(char *error)
{
	ft_printf("%s\n", error);
	exit(EXIT_FAILURE);
}
