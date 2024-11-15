/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhenriq2 <jhenriq2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:29:59 by jhenriq2          #+#    #+#             */
/*   Updated: 2024/10/14 14:38:50 by jhenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(const char *str)
{
	long	i;
	int		result;
	int		sign;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 45)
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == 43)
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (sign * result);
}
/**@brief Create a stack with the command line values
 * @param *a Stack a
 * @param av av
 * @param flag_ac_2 If ac is 2 then have to use a split
 * @return Integer with sign
 */

void	stack_init(t_stack_node **a, char **av, bool flag_ac_2)
{
	long	nbr;
	int		i;

	i = 0;
	while (av[i])
	{
		if (syntax_error(av[i]))
			free_error(a, av, flag_ac_2);
		nbr = ft_atol(av[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			free_error(a, av, flag_ac_2);
		if (rep_error(*a, (int)nbr))
			free_error(a, av, flag_ac_2);
		node_append(a, (int)nbr);
		++i;
	}
	if (flag_ac_2)
		matrix_free(av);
}
