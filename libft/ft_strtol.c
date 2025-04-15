/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 21:21:44 by ngaurama          #+#    #+#             */
/*   Updated: 2024/12/12 13:54:45 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strtol_helper(char **ptr, int *sign)
{
	while (**ptr == ' ')
		(*ptr)++;
	if (**ptr == '-')
	{
		*sign = -1;
		(*ptr)++;
	}
	else if (**ptr == '+')
		(*ptr)++;
}

long	result_long(int sign)
{
	if (sign == 1)
		return (LONG_MAX);
	return (LONG_MIN);
}

long	ft_strtol(char *str, char **endptr)
{
	char	*ptr;
	long	result;
	int		sign;
	int		digit;

	result = 0;
	sign = 1;
	ptr = str;
	ft_strtol_helper(&ptr, &sign);
	while (*ptr && ft_isdigit(*ptr))
	{
		digit = *ptr - '0';
		if (result > (LONG_MAX - digit) / 10)
		{
			result = result_long(sign);
			if (endptr)
				*endptr = (char *)ptr;
			return (result);
		}
		result = result * 10 + digit;
		ptr++;
	}
	if (endptr)
		*endptr = (char *)ptr;
	return (sign * result);
}
