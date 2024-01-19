/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 09:44:22 by tsaari            #+#    #+#             */
/*   Updated: 2024/01/19 13:39:08 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_not_flagged(t_stack **stack_a, t_stack **stack_b)
{
	int x;

	x =ft_lstsize(*stack_a);
	while(x > 0)
	{
		if ((*stack_a)->flag != -1 && (*stack_a)->order > (x / 2))
			push_a_to_b(stack_a, stack_b);
		else
			rotate_a(stack_a, stack_b);
		x--;
	}
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

void move_smallindex_nodes(t_stack **stack_a, t_stack **stack_b, t_stack *node_a, t_stack *node_b)
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
	int a = ft_lstsize(*stack_a);
	int b = ft_lstsize(*stack_b);
	if ((a - node_a->index) > (b - node_b->index))
	{
		while ((a - node_a->index) != (b - node_b->index))
			reverse_rotate_a(stack_a, stack_b);
		while (node_a->index != 0)
			reverse_rotate_both(stack_a, stack_b);
	}
	else
	{
		while ((a - node_a->index) != (b - node_b->index))
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
		reverse_rotate_a(stack_a, stack_b);

	if (node_b->index < (ft_lstsize(*stack_b) / 2))
	{
		while(node_b->index != 0)
			rotate_b(stack_a, stack_b);
	}
	while(node_b->index != 0)
		reverse_rotate_b(stack_a, stack_b);
	push_b_to_a(stack_a, stack_b);
	reset_costs(stack_a, stack_b);
}

void push_back_node(t_stack **stack_a, t_stack **stack_b, t_stack *node_a, t_stack *node_b)
{
	
	if (node_a->index < (ft_lstsize(*stack_a) / 2) && node_b->index < (ft_lstsize(*stack_b) / 2))
		move_smallindex_nodes(stack_a, stack_b, node_a, node_b);
	else if (node_a->index > (ft_lstsize(*stack_a) / 2) && node_b->index > (ft_lstsize(*stack_b) / 2))
		move_highindex_nodes(stack_a, stack_b, node_a, node_b);
	else
		move_index_low_and_high(stack_a, stack_b, node_a, node_b);
}
void find_cheapest_and_push(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *temp;
	t_stack	*node_a;
	t_stack *node_b;
	int cheapest;

	if (!stack_b || !stack_a)
		exit(1);
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

void sort_big (t_stack **stack_a, t_stack **stack_b)
{
	while (ft_lstsize(*stack_b) != 0)
	{
		find_cheapest_and_push(stack_a, stack_b);
	}
}
