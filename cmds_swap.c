/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:06:15 by tsaari            #+#    #+#             */
/*   Updated: 2024/01/26 14:31:23 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_stack **stack)
{
    t_stack *tmp1 = *stack;
    t_stack *tmp2 = (*stack)->next;

    tmp1->next = tmp2->next;
    tmp2->next = tmp1;
    *stack = tmp2;

	return (1);
}

void	swap_a(t_stack **stack_a, t_stack **stack_b)
{
	if(swap(stack_a) == 0)
		return ;
	update_indexes(stack_a, stack_b);
	write(1, "sa\n", 3);
}

void	swap_b(t_stack **stack_a, t_stack **stack_b)
{
	if(swap(stack_b) == 0)
		return ;
	update_indexes(stack_a, stack_b);
	write(1, "sb\n", 3);
}

void	swap_both(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	update_indexes(stack_a, stack_b);
	write(1, "ss\n", 3);
}
