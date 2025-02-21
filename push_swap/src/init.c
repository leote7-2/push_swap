/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoleote <joaoleote@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 00:07:10 by joaoleote         #+#    #+#             */
/*   Updated: 2024/11/27 00:07:11 by joaoleote        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

long int	ft_atol(char *str)
{
	long int	result;
	int			sign;
	int			i;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}


void	stack_init(t_stack_node **a, char **av, int to_free)
{
	long	nbr;
	int		i;

	i = -1;
	while (av[++i])
	{
		if (syntax_error(av[i]) == 1)
		{
			if (to_free)
				matrix_free(av);
			handle_error(a);
		}
		nbr = ft_atol(av[i]);
		if (nbr > INT_MAX || nbr < INT_MIN
			|| rep_error(*a, (int)nbr) == 1)
		{
			if (to_free)
				matrix_free(av);
			handle_error(a);
		}
		node_append(a, (int)nbr);
	}
	if (to_free)
		matrix_free(av);
}