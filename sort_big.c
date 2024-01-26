/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 09:44:22 by tsaari            #+#    #+#             */
/*   Updated: 2024/01/26 14:22:58 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_back_node(t_stack **stack_a, t_stack **stack_b, t_stack *node_a, t_stack *node_b)
{

	if (node_a->index <= (ft_lstsize_ps(*stack_a) / 2) && node_b->index <= (ft_lstsize_ps(*stack_b) / 2))
		move_smallindex_nodes(stack_a, stack_b, node_a, node_b);
	else if (node_a->index > (ft_lstsize_ps(*stack_a) / 2) && node_b->index > (ft_lstsize_ps(*stack_b) / 2))
		move_highindex_nodes(stack_a, stack_b, node_a, node_b);
	else
		move_index_low_and_high(stack_a, stack_b, node_a, node_b);
}

void	find_cheapest_and_push(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *temp;
	t_stack	*node_a;
	t_stack *node_b;
	int cheapest;

	node_b = *stack_b;
	cheapest = INT_MAX;
	temp = *stack_b;
	node_a = find_nearest_bigger(stack_a, temp->num);
	while (temp != NULL)
	{
		if (temp->cost < cheapest)
		{
			cheapest = temp->cost;
			node_b = temp;
			node_a = find_nearest_bigger(stack_a, temp->num);
		}
		temp = temp->next;
	}
	push_back_node(stack_a, stack_b, node_a, node_b);
}

void	sort_big (t_stack **stack_a, t_stack **stack_b)
{
	t_stack *temp;

	flag_increasing(*stack_a);
	push_not_flagged(stack_a, stack_b);
	reset_costs(stack_a, stack_b);
	while (ft_lstsize_ps(*stack_b) != 0)
		find_cheapest_and_push(stack_a, stack_b);
	temp = lowest(stack_a);
	while (temp->index != 0)
	{
		if (temp->index < ft_lstsize_ps(*stack_a) / 2)
			rotate_a(stack_a, stack_b);
		else
			reverse_rotate_a(stack_a, stack_b);
	}
}
