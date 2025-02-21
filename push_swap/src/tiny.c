/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoleote <joaoleote@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 00:06:31 by joaoleote         #+#    #+#             */
/*   Updated: 2024/11/27 00:06:32 by joaoleote        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/push_swap.h"

int	sorted_stack(t_stack_node *a)
{
	if (!a)
		return (1);
	while (a->next)
	{
		if (a->content > a->next->content)
			return (0);
		a = a->next;
	}
	return (1);
}

t_stack_node	*find_highest(t_stack_node *stack)
{
	long int			highest;
	t_stack_node		*highest_node;

	highest = LONG_MIN;
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->content > highest)
		{
			highest_node = stack;
			highest = stack->content;
		}
		stack = stack->next;
	}
	return (highest_node);
}

void	sorted_three(t_stack_node **a)
{
	t_stack_node	*highest_node;

	highest_node = find_highest(*a);
	if (highest_node == *a)
		ra(a);
	else if ((*a)->next == highest_node)
		rra(a);
	if ((*a)->content > (*a)->next->content)
		sa(*a);
}

void	sorted_small(t_stack_node **a)
{
	if (stack_len(*a) == 2)
		sa(*a);
	else if (stack_len(*a) == 3)
		sorted_three(a);
}
