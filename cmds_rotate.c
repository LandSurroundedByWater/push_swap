/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:06:21 by tsaari            #+#    #+#             */
/*   Updated: 2024/01/29 10:28:06 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_top_to_bottom(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	(*stack) = (*stack)->next;
	ft_lstadd_back_ps(stack, temp);
}

void	rotate_a(t_stack **stack_a, t_stack **stack_b)
{
	rotate_top_to_bottom(stack_a);
	update_indexes(stack_a, stack_b);
	write(1, "ra\n", 3);
}

void	rotate_b(t_stack **stack_a, t_stack **stack_b)
{
	rotate_top_to_bottom(stack_b);
	update_indexes(stack_a, stack_b);
	write(1, "rb\n", 3);
}

void	rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	rotate_top_to_bottom(stack_a);
	rotate_top_to_bottom(stack_b);
	update_indexes(stack_a, stack_b);
	write(1, "rr\n", 3);
}
