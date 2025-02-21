/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoleote <joaoleote@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 00:07:28 by joaoleote         #+#    #+#             */
/*   Updated: 2024/11/27 00:07:30 by joaoleote        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	rotate(t_stack_node **top_node)
{
	t_stack_node	*last_node;
	t_stack_node	*new_top;

	if (!(*top_node) || !(*top_node)->next)
		return ;
	last_node = lst_last(*top_node);
	new_top = (*top_node)->next;
	last_node->next = *top_node;
	(*top_node)->prev = last_node;
	(*top_node)->next = NULL;
	*top_node = new_top;
	new_top->prev = NULL;
}

void	ra(t_stack_node **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack_node **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
