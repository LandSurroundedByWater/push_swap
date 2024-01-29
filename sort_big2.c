/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:21:27 by tsaari            #+#    #+#             */
/*   Updated: 2024/01/29 09:37:37 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_pushable(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (temp)
	{
		if (temp->flag != -1)
			return (-1);
		temp = temp->next;
	}
	return (0);
}

void	push_not_flagged(t_stack **stack_a, t_stack **stack_b)
{
	int	x;

	x = ft_lstsize_ps(*stack_a);
	while (x > 0 && check_if_pushable(*stack_a) == -1)
	{
		if ((*stack_a)->flag != -1 && (*stack_a)->order < (x / 2))
			push_a_to_b(stack_a, stack_b);
		else
			rotate_a(stack_a, stack_b);
		x--;
	}
	x = ft_lstsize_ps(*stack_a);
	while (x > 0 && check_if_pushable(*stack_a) == -1)
	{
		if ((*stack_a)->flag != -1)
			push_a_to_b(stack_a, stack_b);
		else
			rotate_a(stack_a, stack_b);
		x--;
	}
}

void	mv_sm_nds(t_stack **st_a, t_stack **st_b, t_stack *n_a, t_stack *n_b)
{
	if (n_a->index > n_b->index)
	{
		while (n_a->index != n_b->index)
			rotate_a(st_a, st_b);
		while (n_a->index != 0)
			rotate_both(st_a, st_b);
	}
	else
	{
		while (n_b->index != n_a->index)
			rotate_b(st_a, st_b);
		while (n_b->index != 0)
			rotate_both(st_a, st_b);
	}
	push_b_to_a(st_a, st_b);
	reset_costs(st_a, st_b);
}

void	mv_high_nds(t_stack **st_a, t_stack **st_b, t_stack *n_a, t_stack *n_b)
{
	int	a;
	int	b;

	a = ft_lstsize_ps(*st_a);
	b = ft_lstsize_ps(*st_b);
	if ((a - n_a->index) > (b - n_b->index))
	{
		while ((a - n_a->index) != (b - n_b->index))
			reverse_rotate_a(st_a, st_b);
		while (n_a->index != 0)
			reverse_rotate_both(st_a, st_b);
	}
	else
	{
		while ((a - n_a->index) != (b - n_b->index))
			reverse_rotate_b(st_a, st_b);
		while (n_b->index != 0)
			reverse_rotate_both(st_a, st_b);
	}
	push_b_to_a(st_a, st_b);
	reset_costs(st_a, st_b);
}

void	mv_l_and_h(t_stack **st_a, t_stack **st_b, t_stack *n_a, t_stack *n_b)
{
	if (n_a->index < (ft_lstsize_ps(*st_a) / 2))
	{
		while (n_a->index != 0)
			rotate_a(st_a, st_b);
	}
	while (n_a->index != 0)
		reverse_rotate_a(st_a, st_b);
	if (n_b->index < (ft_lstsize_ps(*st_b) / 2))
	{
		while (n_b->index != 0)
			rotate_b(st_a, st_b);
	}
	while (n_b->index != 0)
		reverse_rotate_b(st_a, st_b);
	push_b_to_a(st_a, st_b);
	reset_costs(st_a, st_b);
}
