/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:06:31 by tsaari            #+#    #+#             */
/*   Updated: 2024/01/26 09:22:37 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *temp;
	t_stack *new;

	temp = *stack_a;
	new = ft_lstnew_ps(temp->num, temp->index, temp->order);
	if (!new)
	{
		ft_free(stack_a);
		if (stack_b != NULL)
			ft_free(stack_b);
		exit(1);
	}
	ft_lstadd_front_ps(stack_b, new);
	*stack_a = (*stack_a)->next;
	if ((temp != NULL))
		free(temp);
	update_indexes(stack_a, stack_b);
	write(1, "pb\n", 3);
}

void	push_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *temp;
	t_stack *new;

	temp = *stack_b;
	new = ft_lstnew_ps(temp->num, temp->index, temp->order);
	if (!new)
	{
		ft_free(stack_a);
		if (stack_b != NULL)
			ft_free(stack_b);
		exit(1);
	}
	ft_lstadd_front_ps(stack_a, new);
	*stack_b = (*stack_b)->next;
	if ((temp != NULL))
		free(temp);
	update_indexes(stack_a, stack_b);
	write(1, "pa\n", 3);
}
