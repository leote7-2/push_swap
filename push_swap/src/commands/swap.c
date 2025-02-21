/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoleote <joaoleote@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 00:07:23 by joaoleote         #+#    #+#             */
/*   Updated: 2024/11/27 00:07:24 by joaoleote        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	swap(t_stack_node *head)
{
	int	tmp;

	if (head && head->next)
	{
		tmp = head->content;
		head->content = head->next->content;
		head->next->content = tmp;
	}
}

void	sa(t_stack_node *a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack_node *b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack_node *a, t_stack_node *b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
