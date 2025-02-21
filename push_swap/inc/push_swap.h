/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhenriq2 <jhenriq2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:26:05 by jhenriq2          #+#    #+#             */
/*   Updated: 2024/10/16 17:32:28 by jhenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include "../Libft/libft.h"

typedef struct s_lists
{
	int				content;
	int				price;
	int				current_position;
	int				cheapest;
	int				above_average;
	struct s_lists	*target;
	struct s_lists	*next;
	struct s_lists	*prev;
}					t_stack_node;

/* ERRORS.C */
void				matrix_free(char **argv);
void				stack_free(t_stack_node **stack);
void				handle_error(t_stack_node **a);
int					syntax_error(char *str);
int					rep_error(t_stack_node *a, int num);
/* INIT.C */
long int			ft_atol(char *str);
void				stack_init(t_stack_node **a, char **argv, int to_free);
/* PUSH_SWAP_INIT.C */
void				set_current_position(t_stack_node *stack);
void				set_target_node(t_stack_node *a, t_stack_node *b);
void				set_price(t_stack_node *a, t_stack_node *b);
void				set_cheapest(t_stack_node *stack);
void				init_nodes(t_stack_node *a, t_stack_node *b);
/* PUSH_SWAP.C */
void				move_node(t_stack_node **a, t_stack_node **b);
void				rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node);
void				reverse_rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node);
void				finish_rotation(t_stack_node **stack, t_stack_node *top_node, char stack_name);
/* SORT.C */
void				push_swap(t_stack_node **a, t_stack_node **b);
void				b_nodes_init(t_stack_node *a, t_stack_node *b);
void				b_target(t_stack_node *a, t_stack_node *b);
void				b_to_a(t_stack_node **a, t_stack_node **b);
void				lowest_num_first(t_stack_node **a);
/* TINY.C */
int					sorted_stack(t_stack_node *a);
t_stack_node		*find_highest(t_stack_node *stack);
void				sorted_three(t_stack_node **a);
void				sorted_small(t_stack_node **a);
/* UTILS.C */
void				node_append(t_stack_node **stack, int num);
t_stack_node		*find_tinyest(t_stack_node *stack);
t_stack_node		*cheapest(t_stack_node *stack);
int					stack_len(t_stack_node *a);
t_stack_node		*lst_last(t_stack_node *top_node);
/* COMMANDS */
void				swap(t_stack_node *head);
void				sa(t_stack_node *a);
void				sb(t_stack_node *b);
void				ss(t_stack_node *a, t_stack_node *b);
void				push(t_stack_node **dest, t_stack_node **src);
void				pb(t_stack_node **a, t_stack_node **b);
void				pa(t_stack_node **a, t_stack_node **b);
void				rotate(t_stack_node **top_node);
void				ra(t_stack_node **a);
void				rb(t_stack_node **b);
void				rr(t_stack_node **a, t_stack_node **b);
void				reverse_rotate(t_stack_node **top_node);
void				rra(t_stack_node **a);
void				rrb(t_stack_node **b);
void				rrr(t_stack_node **a, t_stack_node **b);

#endif
