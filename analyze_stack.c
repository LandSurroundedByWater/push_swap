/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:55:50 by tsaari            #+#    #+#             */
/*   Updated: 2024/01/27 10:23:42 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_nearest_bigger(t_stack **stack, int num)
{
	t_stack	*temp;
	t_stack	*nb_node;
	int		nearest_bigger;

	temp = *stack;
	nb_node = NULL;
	nearest_bigger = INT_MAX;
	while (temp)
	{
		if (temp->num > num)
		{
			if (temp->num <= nearest_bigger)
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

int	count_t_cst(t_stack *st_a, t_stack *st_b, t_stack *n_a, t_stack *n_b)
{
	int	stsize_a;
	int	stsize_b;
	int	count;

	count = 0;
	stsize_a = ft_lstsize_ps(st_a);
	stsize_b = ft_lstsize_ps(st_b);
	if (n_a->index < (stsize_a / 2) && n_b->index < (stsize_b / 2))
	{
		if (n_a->order > n_b->order)
			count = n_a->order;
		else
			count = n_b->order;
	}
	else if (n_a->index >= (stsize_a / 2) && n_b->index >= (stsize_b / 2))
	{
		if (n_a->order > n_b->order)
			count = n_a->order;
		else
			count = n_b->order;
	}
	else
		count = n_a->order + n_b->order;
	return (count);
}

void	reset_costs(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node_a;
	t_stack	*node_b;
	int		cost;

	cost = 0;
	node_b = *stack_b;
	count_costs_to_top(stack_a, stack_b);
	while (node_b != NULL)
	{
		node_a = find_nearest_bigger(stack_a, node_b->num);
		cost = count_t_cst(*stack_a, *stack_b, node_a, node_b);
		node_b->flag = node_a->num;
		node_b->cost = cost;
		node_b = node_b->next;
	}
}

void	flag_node(t_stack *stack, t_stack *temp, int max, int div)
{
	while (temp != 0)
	{
		if (temp->order >= max && temp->order <= max + \
		(ft_lstsize_ps(stack) / (ft_lstsize_ps(stack) / \
		(div + ft_lstsize_ps(stack) / 30))))
		{
			max = temp->order;
			temp->flag = -1;
		}
		temp = temp->next;
	}
	temp = stack;
	while (temp->flag != -1)
	{
		if (temp->order >= max && temp->order <= max + \
		(ft_lstsize_ps(stack) / (ft_lstsize_ps(stack) / \
		(div + ft_lstsize_ps(stack) / 30))))
		{
			max = temp->order;
			temp->flag = -1;
		}
		temp = temp->next;
	}
}

void	flag_increasing(t_stack *stack)
{
	t_stack	*temp;
	int		max;
	int		div;

	div = 1;
	max = 1;
	while (div * div <= ft_lstsize_ps(stack))
		div++;
	temp = lowest(&stack);
	flag_node(stack, temp, max, div);
}
