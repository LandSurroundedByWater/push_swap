/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:06:31 by tsaari            #+#    #+#             */
/*   Updated: 2024/01/19 11:06:32 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *tmp;
	t_stack *new;

	if (*stack_a == NULL)
		return;
	tmp = *stack_a;
	new = ft_lstnew((*stack_a)->num, (*stack_a)->index, (*stack_a)->order);
	if (!new)
		exit(1);
	ft_lstadd_front(stack_b, new);
	*stack_a = (*stack_a)->next;
	free(tmp);
	update_indexes(stack_a, stack_b);
	write(1, "pb\n", 3);
}

void	push_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *tmp;
	t_stack *new;

	if (!stack_b)
		return;
	tmp = *stack_b;
	new = ft_lstnew((*stack_b)->num, (*stack_b)->index, (*stack_b)->order);
	if (!new)
		exit(1);
	ft_lstadd_front(stack_a, new);
	*stack_b = (*stack_b)->next;
	free(tmp);
	update_indexes(stack_a, stack_b);
	write(1, "pa\n", 3);

}
