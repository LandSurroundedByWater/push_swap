/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:06:21 by tsaari            #+#    #+#             */
/*   Updated: 2024/01/26 15:21:43 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_bottom_to_top(t_stack **stack)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	tmp1 = ft_last_node(*stack);
	tmp2 = ft_second_last_node(*stack);
	ft_lstadd_front_ps(stack, tmp1);
	tmp2->next = NULL;
}

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
