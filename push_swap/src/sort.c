/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoleote <joaoleote@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 00:06:36 by joaoleote         #+#    #+#             */
/*   Updated: 2024/11/27 00:06:43 by joaoleote        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push_swap(t_stack_node **a, t_stack_node **b)
{
	int	len_stack_a;

	len_stack_a = stack_len(*a);
	if (len_stack_a-- > 3 && !sorted_stack(*a))
		pb(b, a);
	if (len_stack_a-- > 3 && !sorted_stack(*a))
		pb(b, a);
	while (len_stack_a-- > 3 && !sorted_stack(*a))
	{
		init_nodes(*a, *b);
		move_node(a, b);
	}
	sorted_three(a);
	while (*b)
	{
		b_nodes_init(*a, *b);
		b_to_a(a, b);
	}
	set_current_position(*a);
	lowest_num_first(a);
}

void	b_nodes_init(t_stack_node *a, t_stack_node *b)
{
	set_current_position(a);
	set_current_position(b);
	b_target(a, b);
}

void	b_target(t_stack_node *a, t_stack_node *b)
{
	t_stack_node		*status_a;
	t_stack_node		*target_node;
	long int			best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		status_a = a;
		while (status_a)
		{
			if (status_a->content > b->content
				&& status_a->content < best_match_index)
			{
				best_match_index = status_a->content;
				target_node = status_a;
			}
			status_a = status_a->next;
		}
		if (best_match_index == LONG_MAX)
			b->target = find_tinyest(a);
		else
			b->target = target_node;
		b = b->next;
	}
}

void	b_to_a(t_stack_node **a, t_stack_node **b)
{
	finish_rotation(a, (*b)->target, 'a');
	pa(a, b);
}

void	lowest_num_first(t_stack_node **a)
{
	while ((*a)->content != find_tinyest(*a)->content)
	{
		if (find_tinyest(*a)->above_average)
			ra(a);
		else
			rra(a);
	}
}