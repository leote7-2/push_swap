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
# include "Libft/libft.h"

typedef struct s_lists
{
	int				content;
	int				price;
	int				current_position;
	bool			cheapest;
	bool			above_average;
	struct s_lists	*target;
	struct s_lists	*next;
	struct s_lists	*prev;
}					t_stack_node;

/* ALGORITHMS */
void				sorted_tiny(t_stack_node **a);
void				sorted_five(t_stack_node **a, t_stack_node **b);
void				push_swap(t_stack_node **a, t_stack_node **b);

/* CREATE STACK */
void				set_price(t_stack_node *a, t_stack_node *b);
void				set_current_position(t_stack_node *stack);
void				set_cheapest(t_stack_node *b);
void				init_nodes(t_stack_node *a, t_stack_node *b);
void				stack_init(t_stack_node **a, char **av, bool flag_ac_2);

/* UTILS */
void				node_append(t_stack_node **stack, int nbr);
t_stack_node		*find_tinyest(t_stack_node *stack);
t_stack_node		*cheapest(t_stack_node *stack);
int					stack_len(t_stack_node *stack);
bool				sorted_stack(t_stack_node *stack);
void				finish_rotation(t_stack_node **stack,
						t_stack_node *top_node, char name);

/* ERRORS */
void				matrix_free(char **av);
void				stack_free(t_stack_node **stack);
void				free_error(t_stack_node **a, char **av, bool flag_ac_2);
int					syntax_error(char *str);
int					rep_error(t_stack_node *a, int nbr);

/* COMMANDS */
void				sa(t_stack_node **a, bool checker);
void				sb(t_stack_node **b, bool checker);
void				ss(t_stack_node **a, t_stack_node **b, bool checker);
void				pb(t_stack_node **a, t_stack_node **b, bool checker);
void				pa(t_stack_node **a, t_stack_node **b, bool checker);
void				ra(t_stack_node **a, bool checker);
void				rb(t_stack_node **b, bool checker);
void				rr(t_stack_node **a, t_stack_node **b, bool checker);
void				rra(t_stack_node **a, bool checker);
void				rrb(t_stack_node **b, bool checker);
void				rrr(t_stack_node **a, t_stack_node **b, bool checker);

#endif