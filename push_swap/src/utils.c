/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoleote <joaoleote@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 00:06:25 by joaoleote         #+#    #+#             */
/*   Updated: 2024/11/27 00:06:27 by joaoleote        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	node_append(t_stack_node **stack, int nbr)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!node)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	node->content = nbr;
	node->next = NULL;
	if (!*stack)
	{
		node->prev = NULL;
		*stack = node;
	}
	else
	{
		last_node = *stack;
		while (last_node->next)
			last_node = last_node->next;
		last_node->next = node;
		node->prev = last_node;
	}
}

t_stack_node	*find_tinyest(t_stack_node *stack)
{
	t_stack_node	*tiny_node;
	long			tinyest;

	tinyest = LONG_MAX;
	while (stack)
	{
		if (stack->content < tinyest)
		{
			tinyest = stack->content;
			tiny_node = stack;
		}
		stack = stack->next;
	}
	return (tiny_node);
}

t_stack_node	*cheapest(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

int	stack_len(t_stack_node *a)
{
	int	count;

	if (!a)
		return (0);
	count = 0;
	while (a)
	{
		count++;
		a = a->next;
	}
	return (count);
}

t_stack_node	*lst_last(t_stack_node *top_node)
{
	while (top_node->next)
		top_node = top_node->next;
	return (top_node);
}