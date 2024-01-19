/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_stack2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:05:39 by tsaari            #+#    #+#             */
/*   Updated: 2024/01/19 11:58:04 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cost_to_top(t_stack **stack, t_stack *node)
{
	int cost;

	if (!stack || !node)
		ft_free(stack, NULL);
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

		if (!stack_a  || !stack_b)
			ft_free(stack_a, stack_b);
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

t_stack	*lowest_order(t_stack **stack)
{
	t_stack *temp;
	t_stack *lowestnode = NULL;
	int		lowest;

	if (!stack)
		ft_free(stack, NULL);
	lowest = INT_MAX;
	if (!stack)
		exit (1);
	temp = *stack;
	while (temp != 0)
	{
		if (temp->order == -1 && temp->num < lowest)
		{
			lowest = temp->num;
			lowestnode = temp;
		}
		temp = temp->next;
	}
	return (lowestnode);
}

void set_order(t_stack **stack)
{
	int order;

	order = 1;
	while(order <= ft_lstsize(*stack))
	{
		lowest_order(stack)->order = order;
		order++;
	}
}