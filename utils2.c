/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:07:02 by tsaari            #+#    #+#             */
/*   Updated: 2024/01/24 06:22:30 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



t_stack *lowest(t_stack **stack)
{
	t_stack *temp;
	t_stack *lnode;
	int		lowest;

	lnode = NULL;
	lowest = (*stack)->num;
	temp = *stack;
	while (temp != NULL)
	{
		if (temp->num < lowest)
		{
			lnode = temp;
			lowest = temp->num;
		}
		temp = temp->next;
	}
	return (lnode);
}

int is_biggest(t_stack **stack)
{
	t_stack *temp;
	int		biggest;
	int		index;

	biggest = (*stack)->num;
	index	= (*stack)->index;
	temp = *stack;
	while (temp != NULL)
	{
		if (temp->num > biggest)
		{
			biggest = temp->num;
			index	= temp->index;
		}
		temp = temp->next;
	}
	return (index);
}

void	reset_flags(t_stack *stack)
{
	t_stack *temp;

	temp = stack;
	while (temp != NULL)
	{
		temp->order = 0;
		temp = temp->next;
	}
}

void	update_indexes(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *temp_a;
	t_stack *temp_b;
	int newindex;

	temp_a = NULL;
	temp_b = NULL;

	if (*stack_a != NULL)
		temp_a = *stack_a;
	if (*stack_b != NULL)
		temp_b = *stack_b;
	newindex = 0;
	while (temp_a != NULL)
	{
		temp_a->index = newindex;
		temp_a = temp_a->next;
		newindex++;
	}
	newindex = 0;
	while (temp_b != NULL)
	{
		temp_b->index =  newindex;
		temp_b = temp_b->next;
		newindex++;
	}
}