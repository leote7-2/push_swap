/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoleote <joaoleote@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 00:07:35 by joaoleote         #+#    #+#             */
/*   Updated: 2024/11/27 00:07:37 by joaoleote        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	reverse_rotate(t_stack_node **top_node)
{
	t_stack_node	*last_node;

	if (!(*top_node) || !(*top_node)->next)
		return ;
	last_node = lst_last(*top_node);
	last_node->prev->next = NULL;
	last_node->next = *top_node;
	last_node->prev = NULL;
	*top_node = last_node;
	last_node->next->prev = last_node;
}

void	rra(t_stack_node **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack_node **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}
