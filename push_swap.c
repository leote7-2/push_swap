/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhenriq2 <jhenriq2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:21:44 by jhenriq2          #+#    #+#             */
/*   Updated: 2024/11/11 17:21:44 by jhenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both(t_stack_node **a,
						t_stack_node **b, t_stack_node *cheapest_node)
{
	while (*a != cheapest_node->target && *b != cheapest_node)
		rr(a, b, false);
	set_current_position(*a);
	set_current_position(*b);
}

static void	reverse_rotate_both(t_stack_node **a,
								t_stack_node **b,
								t_stack_node *cheapest_node)
{
	while (*a != cheapest_node->target && *b != cheapest_node)
		rrr(a, b, false);
	set_current_position(*a);
	set_current_position(*b);
}

void	finish_rotation(t_stack_node **stack, t_stack_node *top_node,
							char name)
{
	while (*stack != top_node)
	{
		if (name == 'a')
		{
			if (top_node->above_average)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (name == 'b')
		{
			if (top_node->above_average)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}

static void	move_node(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = return_cheapest(*b);
	if (cheapest_node->above_average && cheapest_node->target->above_average)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_average)
		&& !(cheapest_node->target->above_average))
		reverse_rotate_both(a, b, cheapest_node);
	finish_rotation(b, cheapest_node, 'b');
	finish_rotation(a, cheapest_node->target, 'a');
	pa(a, b, false);
}

/*
 * Push all nodes to B
 * Choses the cheapest to every configuration
 * Push all organized nodes to A 
*/
void	push_swap(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*small;
	int				len_a;

	len_a = stack_len(*a);
	if (len_a == 5)
		sorted_five(a, b);
	else
	{
		while (len_a-- > 3)
			pb(b, a, false);
	}
	sorted_tiny(a);
	while (*b)
	{
		init_node(*a, *b);
		move_nodes(a, b);
	}
	set_current_position(*a);
	small = find_small(*a);
	if (small->above_average)
		while (*a != small)
			ra(a, false);
	else
		while (*a != small)
			rra(a, false);
}
