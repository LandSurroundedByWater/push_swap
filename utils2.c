/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:07:02 by tsaari            #+#    #+#             */
/*   Updated: 2024/01/19 14:00:05 by tsaari           ###   ########.fr       */
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
	if (!stack)
		ft_free(stack, NULL);
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
	if (!stack)
		ft_free(stack, NULL);
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

	if (!stack)
		ft_free(&stack, NULL);
	temp = stack;
	while (temp != NULL)
	{
		temp->order = 0;
		temp = temp->next;
	}
}