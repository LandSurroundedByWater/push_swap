/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 08:56:29 by tsaari            #+#    #+#             */
/*   Updated: 2024/01/26 10:39:04 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int				num;
	int 			index;
	int				order;
	int				flag;
	int				cost;
	struct s_stack	*next;
}	t_stack;

void	ft_lstiter_ps(t_stack *stack, void (*f)(t_stack *));
void	printnode(t_stack *node);

int		is_biggest(t_stack **stack);
void	update_indexes(t_stack **stack_a, t_stack **stack_b);
int		is_sorted(t_stack *stack);
void	push_not_flagged(t_stack **stack_a, t_stack **stack_b);
void	set_order(t_stack **stack);
int		find_index(t_stack *stack, int targetNum);
void	count_costs_to_top(t_stack **stack_a, t_stack **stack_b);
void	cost_to_top(t_stack **stack, t_stack *node);
void	reset_flags(t_stack *stack);
void	reset_costs(t_stack **stack_a, t_stack **stack_b);
int		count_total_cost(t_stack *stack_a, t_stack *stack_b, t_stack *node_a, t_stack *node_b);
void	find_cheapest_and_push(t_stack **stack_a, t_stack **stack_b);
void	flag_increasing(t_stack *stack);

void	ft_error();
void	ft_free(t_stack **stack);
int		check_dublicates(t_stack *stack_a, t_stack *new);
void	check_isdigit(char *str);
t_stack	*ft_lstnew_ps(int num, int index, int order);
int		ft_lstsize_ps(t_stack *stack);
void	ft_lstadd_front_ps(t_stack **stack, t_stack *new);
void	ft_lstadd_back_ps(t_stack **stack, t_stack *newnode);
t_stack	*ft_last_node(t_stack *stack);
t_stack	*ft_second_last_node(t_stack *stack);
t_stack	*lowest(t_stack **stack);
t_stack	*lowest_order(t_stack **stack);
t_stack	*find_nearest_bigger(t_stack **stack, int num);
long ft_atol(const char *str);

void	push_a_to_b(t_stack **stack_a, t_stack **stack_b);
void	push_b_to_a(t_stack **stack_b, t_stack **stack_a);
void	swap_a(t_stack **stack_a, t_stack **stack_b);
void	swap_b(t_stack **stack_a, t_stack **stack_b);
void	swap_both(t_stack **stack_a, t_stack **stack_b);

void	rotate_bottom_to_top(t_stack **stack);
void	rotate_top_to_bottom(t_stack **stack);
void	rotate_a(t_stack **stack_a, t_stack **stack_b);
void	rotate_b(t_stack **stack_a, t_stack **stack_b);
void	rotate_both(t_stack **stack_a, t_stack **stack_b);
void	reverse_rotate_a(t_stack **stack_a, t_stack **stack_b);
void	reverse_rotate_b(t_stack **stack_a, t_stack **stack_b);
void	reverse_rotate_both(t_stack **stack_a, t_stack **stack_b);

void	sort_three(t_stack **stack, t_stack **stack_b);
void	sort_five(t_stack **stack_a, t_stack **stack_b);
void	sort_small(t_stack **stack_a, t_stack **stack_b);
void	sort_big (t_stack **stack_a, t_stack **stack_b);


#endif
