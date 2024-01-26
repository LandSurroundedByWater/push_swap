/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:21:27 by tsaari            #+#    #+#             */
/*   Updated: 2024/01/26 14:23:14 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_pushable(t_stack *stack)
{
	t_stack *temp;

	temp = stack;
	while(temp)
	{
		if(temp->flag != -1)
			return (-1);
		temp = temp->next;
	}
	return (0);
}

void	push_not_flagged(t_stack **stack_a, t_stack **stack_b)
{
	int x;

	x =ft_lstsize_ps(*stack_a);
	while(x > 0 && check_if_pushable(*stack_a) == -1)
	{
		if ((*stack_a)->flag != -1 && (*stack_a)->order > (x / 2))
			push_a_to_b(stack_a, stack_b);
		else
			rotate_a(stack_a, stack_b);
		x--;
	}
	x =ft_lstsize_ps(*stack_a);
	while(x > 0 && check_if_pushable(*stack_a) == -1)
	{
		if ((*stack_a)->flag != -1)
			push_a_to_b(stack_a, stack_b);
		else
			rotate_a(stack_a, stack_b);
		x--;
	}
}

void	move_smallindex_nodes(t_stack **stack_a, t_stack **stack_b, t_stack *node_a, t_stack *node_b)
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

void	move_highindex_nodes(t_stack **stack_a, t_stack **stack_b, t_stack *node_a, t_stack *node_b)
{
	int a = ft_lstsize_ps(*stack_a);
	int b = ft_lstsize_ps(*stack_b);
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
void	move_index_low_and_high(t_stack **stack_a, t_stack **stack_b, t_stack *node_a, t_stack *node_b)
{
	if (node_a->index < (ft_lstsize_ps(*stack_a) / 2))
	{
		while(node_a->index != 0)
			rotate_a(stack_a, stack_b);
	}
	while(node_a->index != 0)
		reverse_rotate_a(stack_a, stack_b);

	if (node_b->index < (ft_lstsize_ps(*stack_b) / 2))
	{
		while(node_b->index != 0)
			rotate_b(stack_a, stack_b);
	}
	while(node_b->index != 0)
		reverse_rotate_b(stack_a, stack_b);
	push_b_to_a(stack_a, stack_b);
	reset_costs(stack_a, stack_b);
}
