/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:07:02 by tsaari            #+#    #+#             */
/*   Updated: 2024/01/25 08:33:52 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_dublicates(t_stack *stack_a, t_stack *new)
{
	t_stack *temp;

	while(stack_a != NULL)
	{
		temp = stack_a;
		while(temp != NULL)
		{
			if(temp->num == new->num)
				return (0);
			temp = temp->next;
		}
		stack_a = stack_a->next;
	}
	return (1);
}

t_stack *lowest(t_stack **stack)
{
	t_stack *temp;
	t_stack *lnode;
	int		lowest;

	lnode = NULL;
	lowest = INT_MAX;
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

	temp_a = *stack_a;
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