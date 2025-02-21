/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoleote <joaoleote@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 00:06:58 by joaoleote         #+#    #+#             */
/*   Updated: 2024/11/27 00:06:59 by joaoleote        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	move_node(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = cheapest(*a);
	if (cheapest_node->above_average
		&& cheapest_node->target->above_average)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_average)
		&& !(cheapest_node->target->above_average))
		reverse_rotate_both(a, b, cheapest_node);
	finish_rotation(a, cheapest_node, 'a');
	finish_rotation(b, cheapest_node->target, 'b');
	pb(b, a);
}

void	finish_rotation(t_stack_node **stack, t_stack_node *top_node, char name)
{
	while (*stack != top_node)
	{
		if (name == 'a')
		{
			if (top_node->above_average)
				ra(stack);
			else
				rra(stack);
		}
		else if (name == 'b')
		{
			if (top_node->above_average)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

void	rotate_both(t_stack_node **a,
						t_stack_node **b,
						t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target
		&& *a != cheapest_node)
		rr(a, b);
	set_current_position(*a);
	set_current_position(*b);
}

void	reverse_rotate_both(t_stack_node **a,
								t_stack_node **b,
								t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target
		&& *a != cheapest_node)
		rrr(a, b);
	set_current_position(*a);
	set_current_position(*b);
}
