/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:30:46 by tsaari            #+#    #+#             */
/*   Updated: 2024/01/26 14:30:59 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_last_node(t_stack *stack)
{
	while (stack->next != 0)
		stack = stack->next;
	return (stack);
}

t_stack	*ft_second_last_node(t_stack *stack)
{
	while (stack->next->next != 0)
		stack = stack->next;
	return (stack);
}

void	check_dublicates(t_stack *stack_a, t_stack *new)
{
	t_stack *temp;

	while(stack_a != NULL)
	{
		temp = stack_a;
		while(temp != NULL)
		{
			if(temp->num == new->num)
			{
				ft_free(&stack_a);
				ft_error();
			}
			temp = temp->next;
		}
		stack_a = stack_a->next;
	}
}

t_stack	*lowest(t_stack **stack)
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

int	is_biggest(t_stack **stack)
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