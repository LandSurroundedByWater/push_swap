/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 09:44:22 by tsaari            #+#    #+#             */
/*   Updated: 2024/01/18 14:41:53 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_not_flagged(t_stack **stack_a, t_stack **stack_b)
{
	int x;

	x =ft_lstsize(*stack_a);
	while(x > 0)
	{
		if ((*stack_a)->flag != -1)
			push_a_to_b(stack_a, stack_b);
		else
			rotate_a(stack_a, stack_b);
		x--;
	}
}
void	cost_to_top(t_stack **stack, t_stack *node)
{
	int cost;

	cost = 0;

	if (node->index > (ft_lstsize(*stack) / 2))
		cost = ft_lstsize(*stack) - node->index + 1;
	else
		cost = node->index;
	node->order = cost;
}

void count_costs_to_top(t_stack **stack_a, t_stack **stack_b)
{
		t_stack *temp;

		temp = *stack_b;
		while (temp != NULL)
		{
			cost_to_top(stack_b, temp);
			temp = temp->next;
		}
		temp = *stack_a;
		while (temp != NULL)
		{
			cost_to_top(stack_a, temp);
			temp = temp->next;
		}
}
void move_lowindex_nodes(t_stack **stack_a, t_stack **stack_b, t_stack *node_a, t_stack *node_b)
{
	if (node_a->index > node_b->index)
	{
		while (node_a->index != node_b->index)
			rotate_a(stack_a, stack_b);
		while (node_a->index != 0)
			rotate_both(stack_a, stack_b);
	}
	else
	{
		while (node_b->index != node_a->index)
			rotate_b(stack_a, stack_b);
		while (node_b->index != 0)
			rotate_both(stack_a, stack_b);
	}
	push_b_to_a(stack_a, stack_b);
	reset_costs(stack_a, stack_b);
}

void move_highindex_nodes(t_stack **stack_a, t_stack **stack_b, t_stack *node_a, t_stack *node_b)
{
	if (node_a->index > node_b->index)
	{
		while (node_a->index != node_b->index)
			reverse_rotate_a(stack_a, stack_b);
		while (node_a->index != 0)
			reverse_rotate_both(stack_a, stack_b);
	}
	else
	{
		while (node_b->index != node_a->index)
			reverse_rotate_b(stack_a, stack_b);
		while (node_b->index != 0)
			reverse_rotate_both(stack_a, stack_b);
	}
	push_b_to_a(stack_a, stack_b);
	reset_costs(stack_a, stack_b);
}
void move_index_low_and_high(t_stack **stack_a, t_stack **stack_b, t_stack *node_a, t_stack *node_b)
{
	if (node_a->index < (ft_lstsize(*stack_a) / 2))
	{
		while(node_a->index != 0)
			rotate_a(stack_a, stack_b);
	}
	while(node_a->index != 0)
		reverse_rotate_a(stack_a, stack_a);

	if (node_b->index < (ft_lstsize(*stack_b) / 2))
	{
		while(node_b->index != 0)
			rotate_a(stack_a, stack_b);
	}
	while(node_b->index != 0)
		reverse_rotate_a(stack_a, stack_a);
	push_b_to_a(stack_a, stack_b);
	reset_costs(stack_a, stack_b);
}

void push_back_node(t_stack **stack_a, t_stack **stack_b, t_stack *node_a, t_stack *node_b)
{
	if (node_a->index < (ft_lstsize(*stack_a) / 2) && node_b->index < (ft_lstsize(*stack_b) / 2))
	{
		move_lowindex_nodes(stack_a, stack_b, node_a, node_b);
	}

	else if (node_a->index > (ft_lstsize(*stack_a) / 2) && node_b->index > (ft_lstsize(*stack_b) / 2))
	{
		move_highindex_nodes(stack_a, stack_b, node_a, node_b);
	}
	else
	{
		move_index_low_and_high(stack_a, stack_b, node_a, node_b);
	}

	printf("\n\n PUSHED to %d in Stack A\n", node_a->num);
	ft_lstiter(*stack_a, &printnode);

	printf("\n\n PUSHED %d from Stack B\n", node_b->num);
	ft_lstiter(*stack_b, &printnode);

}
void find_cheapest_and_push(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *temp;
	t_stack	*node_a;
	t_stack *node_b;

	int cheapest;
	node_a = *stack_a;
	node_b = *stack_b;
	cheapest = (*stack_b)->cost;
	if (!stack_b)
		exit(1);
	temp = *stack_b;
	node_a = find_nearest_bigger(stack_a, temp->num);
	while (temp != NULL)
	{
		if (temp->cost < cheapest)
		{
			node_b = temp;
			node_a = find_nearest_bigger(stack_a, temp->num);
			cheapest = temp->cost;
		}
		temp = temp->next;
	}
	while (ft_lstsize(*stack_b) != 0)
		push_back_node(stack_a, stack_b, node_a, node_b);
}
