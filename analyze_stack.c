/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:09:21 by tsaari            #+#    #+#             */
/*   Updated: 2024/01/19 11:46:54 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

t_stack *find_nearest_bigger(t_stack **stack, int num)
{
	t_stack *temp;
	t_stack *nb_node;
	int nearest_bigger;

	if (!stack)
		ft_free(stack, NULL);
	temp = *stack;
	nb_node = NULL;
	nearest_bigger = INT_MAX;
	while (temp != NULL)
	{
		if (temp->num > num)
		{
			if (temp->num < nearest_bigger)
			{
				nearest_bigger = temp->num;
				nb_node = temp;
			}
		}
		temp = temp->next;
	}
	if (nb_node == NULL)
		return (lowest(stack));
	return (nb_node);
}

void	flag_increasing(t_stack *stack)
{
	t_stack *temp;
	int max;
	int div;

	if (!stack)
		ft_free(&stack, NULL);
	div = 1;
	max = 1;
	while (div * div <= ft_lstsize(stack))
		div++;
	temp = stack;
	while (temp->order != 1)
		temp = temp->next;
	while (temp != NULL)
	{
		if (temp->order >= max && temp->order <= max + (ft_lstsize(stack) / div + ft_lstsize(stack) / 50))
		{
			max = temp->order;
			temp->flag = -1;
		}
		temp = temp->next;
	}
	temp = stack;
	while (temp->flag != -1)
	{
		if (temp->order >= max && temp->order <= max + (ft_lstsize(stack) / div + ft_lstsize(stack) / 50))
		{
			max = temp->order;
			temp->flag = -1;
		}
		temp = temp->next;
	}
}

int count_total_cost(t_stack *stack_a, t_stack *stack_b, t_stack *node_a, t_stack *node_b)
{
	int stsize_a;
	int stsize_b;
	int count = 0;

	if (!node_a || !node_b || !stack_a || !stack_b)
		ft_free(&stack_a, &stack_b);
	stsize_a = ft_lstsize(stack_a);
	stsize_b = ft_lstsize(stack_b);
	if (node_a->index < (stsize_a / 2) || node_b->index < (stsize_b / 2))
	{
		if (node_a->order > node_b->order)
			count = node_a->order;
		else
			count = node_b->order;
	}
	else if (node_a->index >= (stsize_a / 2) && node_b->index >= (stsize_b / 2))
	{
		if (node_a->order > node_b->order)
			count = node_a->order;
		else
			count = node_b->order;
	}
	else
		count = node_a->order + node_b->order;
	return count;
}

void reset_costs(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *node_a;
	t_stack *node_b;
	int cost;

	if (!stack_a || !stack_b)
		ft_free(stack_a, stack_b);
	cost = 0;
	node_b = *stack_b;
	count_costs_to_top(stack_a, stack_b);
	while (node_b != NULL)
	{
		node_a = find_nearest_bigger(stack_a, node_b->num);
		cost = count_total_cost(*stack_a, *stack_b, node_a, node_b);
		node_b->flag = node_a->num;
		node_b->cost = cost;
		node_b = node_b->next;
	}
}
