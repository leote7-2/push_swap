/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoleote <joaoleote@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 00:07:04 by joaoleote         #+#    #+#             */
/*   Updated: 2025/02/18 15:58:16 by joaoleote        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**new_av;

	a = NULL;
	b = NULL;
	new_av = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	if (ac == 2)
	{
		new_av = ft_split(av[1], ' ');
		stack_init(&a, new_av, 1);
	}
	else
		stack_init(&a, av + 1, 0);
	if (!sorted_stack(a))
	{
		if (stack_len(a) == 2 || stack_len(a) == 3)
			sorted_small(&a);
		else
			push_swap(&a, &b);
	}
	stack_free(&a);
	return (0);
}
