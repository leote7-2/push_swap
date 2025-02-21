/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoleote <joaoleote@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 00:06:52 by joaoleote         #+#    #+#             */
/*   Updated: 2024/11/27 00:06:54 by joaoleote        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	set_current_position(t_stack_node *stack)
{
	int	i;
	int	center;

	i = 0;
	if (!stack)
		return ;
	center = stack_len(stack) / 2;
	while (stack)
	{
		stack->current_position = i;
		if (i <= center)
			stack->above_average = 1;
		else
			stack->above_average = 0;
		stack = stack->next;
		i++;
	}
}

void	set_target_node(t_stack_node *a, t_stack_node *b)
{
	t_stack_node		*current_b;
	t_stack_node		*target_b;
	long int			best_friends;

	while (a)
	{
		best_friends = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->content < a->content && current_b->content > best_friends)
			{
				best_friends = current_b->content;
				target_b = current_b;
			}
			current_b = current_b->next;
		}
		if (best_friends == LONG_MIN)
			a->target = find_highest(b);
		else
			a->target = target_b;
		a = a->next;
	}
}

void	set_price(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->price = a->current_position;
		if (!(a->above_average))
			a->price = len_a - (a->current_position);
		if (a->target->above_average)
			a->price += a->target->current_position;
		else
			a->price += len_b - (a->target->current_position);
		a = a->next;
	}
}

void	set_cheapest(t_stack_node *stack)
{
	t_stack_node		*bf_node;
	long int			bf_value;

	if (!stack)
		return ;
	bf_value = LONG_MAX;
	while (stack)
	{
		if (stack->price < bf_value)
		{
			bf_node = stack;
			bf_value = stack->price;
		}
		stack = stack->next;
	}
	bf_node->cheapest = 1;
}

void	init_nodes(t_stack_node *a, t_stack_node *b)
{
	set_current_position(a);
	set_current_position(b);
	set_target_node(a, b);
	set_price(a, b);
	set_cheapest(a);
}
