/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 08:56:29 by tsaari            #+#    #+#             */
/*   Updated: 2024/01/13 14:12:16 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int				num;
	int 			index;
	struct s_stack	*next;
} t_stack;

t_stack	*ft_lstnew(int num, int index);
int		is_biggest(t_stack **stack);
void	update_indexes(t_stack **stack_a, t_stack **stack_b);
int		is_sorted(t_stack *stack);
void	ft_lstiter(t_stack *stack, void (*f)(t_stack *));
void	printnode(t_stack *node);
t_stack	*ft_last_node(t_stack *stack);

void	push_a_to_b(t_stack **stack_a, t_stack **stack_b);
void	printnode(t_stack *node);
void	push_b_to_a(t_stack **stack_b, t_stack **stack_a);
void	swap_a(t_stack **stack_a, t_stack **stack_b);
void	swap_b(t_stack **stack_a, t_stack **stack_b);
void	swap_both(t_stack **stack_a, t_stack **stack_b);
void	ft_lstadd_front(t_stack **stack, t_stack *new);
void	ft_lstadd_back(t_stack **stack, t_stack *newnode);
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

#endif
