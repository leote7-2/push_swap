/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhenriq2 <jhenriq2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:21:21 by jhenriq2          #+#    #+#             */
/*   Updated: 2024/11/11 17:21:21 by jhenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_current_position(t_stack_node *stack)
{
	int	i;
	int	center;

	i = 0;
	if (stack == NULL)
		return ;
	center = stack_len(stack) / 2;
	while (stack)
	{
		stack->current_position = i;
		if (i <= center)
			stack->above_average = true;
		else
			stack->above_average = false;
		stack = stack->next;
		++i;
	}
}

static void	set_target_node(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_a;
	t_stack_node	*target;
	long			best_friend;

	while (b)
	{
		best_friend = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->content > b->content
				&& current_a->content < best_friend)
			{
				best_friend = current_a->content;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (LONG_MAX == best_friend)
			b->target = find_smallest(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	set_price(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (b)
	{
		b->price = b->current_position;
		if (!(b->above_average))
			b->price = len_b - (b->current_position);
		if (b->target->above_average)
			b->price += b->target->current_position;
		else
			b->price += len_a - (b->target->current_position);
		b = b->next;
	}
}

void	set_cheapest(t_stack_node *b)
{
	long			best_friend_value;
	t_stack_node	*best_friend_node;

	if (b == NULL)
		return ;
	best_friend_value = LONG_MAX;
	while (b)
	{
		if (b->price < best_friend_value)
		{
			best_friend_value = b->price;
			best_friend_node = b;
		}
		b = b->next;
	}
	best_friend_node->cheapest = true;
}

void	init_nodes(t_stack_node *a, t_stack_node *b)
{
	set_current_position(a);
	set_current_position(b);
	set_target_node(a, b);
	set_price(a, b);
	set_cheapest(b);
}
