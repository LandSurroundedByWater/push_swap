/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 09:44:22 by tsaari            #+#    #+#             */
/*   Updated: 2024/01/29 08:47:47 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_back(t_stack **st_a, t_stack **st_b, t_stack *n_a, t_stack *n_b)
{
	if (n_a->index <= (ft_lstsize_ps(*st_a) / 2) \
	&& n_b->index <= (ft_lstsize_ps(*st_b) / 2))
		mv_sm_nds(st_a, st_b, n_a, n_b);
	else if (n_a->index > (ft_lstsize_ps(*st_a) / 2) \
	&& n_b->index > (ft_lstsize_ps(*st_b) / 2))
		mv_high_nds(st_a, st_b, n_a, n_b);
	else
		mv_l_and_h(st_a, st_b, n_a, n_b);
}

void	find_cheapest_and_push(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	t_stack	*node_a;
	t_stack	*node_b;
	int		cheapest;

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
	push_back(stack_a, stack_b, node_a, node_b);
}

void	sort_big(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

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
