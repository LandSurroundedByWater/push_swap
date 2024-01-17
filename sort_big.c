/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 09:44:22 by tsaari            #+#    #+#             */
/*   Updated: 2024/01/17 14:41:06 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_not_flagged(t_stack **stack_a, t_stack **stack_b)
{
	int x = ft_lstsize(*stack_a);

	while(x > 0)
	{
		if ((*stack_a)->flag == 1)
			push_a_to_b(stack_a, stack_b);
		else
			rotate_a(stack_a, stack_b);
		x--;
	}
	x = ft_lstsize(*stack_a);
	while(x > 0)
	{
		if ((*stack_a)->flag == 2)
			push_a_to_b(stack_a, stack_b);
		else
			rotate_a(stack_a, stack_b);
		x--;
	}
	x = ft_lstsize(*stack_a);
	while(x > 0)
	{
		if ((*stack_a)->flag == 3)
			push_a_to_b(stack_a, stack_b);
		else
			rotate_a(stack_a, stack_b);
		x--;
	}
	x = ft_lstsize(*stack_a);
	while(x > 0)
	{
		if ((*stack_a)->flag == 4)
			push_a_to_b(stack_a, stack_b);
		else
			rotate_a(stack_a, stack_b);
		x--;
	}
}

void count_costs(t_stack **stack_a, t_stack **stack_b)
{

		t_stack *temp;

		temp = *stack_b;
		while (temp != NULL)
		{
			int costa;
			int costb;
			int nb = find_nearest_bigger(stack_a, temp->num);
			int index = find_index(*stack_a , nb);
			if (index > (ft_lstsize(*stack_a) / 2))
				costa = ft_lstsize(*stack_a) - index + 1;
			else
				costa = index;
			if (temp->index > (ft_lstsize(*stack_b) / 2))
				costb = ft_lstsize(*stack_b) - temp->index + 1;
			else
				costb = temp->index;
			temp->order = costa + costb;
			temp = temp->next;
		}
}




/*void push_back_node(t_stack**stack_a, t_stack **stack_b)
{
	t_stack *temp;
	t_stack *node;

	temp = *stack_b;
	int lowest = INT_MAX;


	while(temp != 0)
	{
		if(temp->order < lowest)
		{
			node = temp;
			lowest = temp->order;
		}
		temp = temp->next;
	}

	if (node->index > ft_lstsize(temp) / 2) //b alhaalla
	{
		if(find_index(*stack_a, find_nearest_bigger(stack_a, node->num)) > ft_lstsize(*stack_a) / 2) //molemmat aalhaalla
		{
			while (find_index(*stack_a, find_nearest_bigger(stack_a, node->num)) != node->index)
			{
				if (find_index(*stack_a, find_nearest_bigger(stack_a, node->num)) < node->index)
					reverse_rotate_a(stack_a, stack_b);
				else
					reverse_rotate_b(stack_a, stack_b);
			}
			while(node->index != 0)
				reverse_rotate_both(stack_a, stack_b);
		}
		else //a ylhaalla b alhaalla
		{
			while (find_index(*stack_a, find_nearest_bigger(stack_a, node->num)) != 0)
				rotate_a(stack_a, stack_b);
			while(node->index != 0)
				reverse_rotate_b(stack_a, stack_b);
		}
		push_b_to_a(stack_a, stack_b);
	}
	else // b ylhaalla
	{
		if(find_index(*stack_a, find_nearest_bigger(stack_a, node->num)) < ft_lstsize(*stack_a) / 2) // myos a ylhaalla
		{
			while (find_index(*stack_a, find_nearest_bigger(stack_a, node->num)) != node->index)
			{
				if (find_index(*stack_a, find_nearest_bigger(stack_a, node->num)) < node->index)
					rotate_a(stack_a, stack_b);
				else
					rotate_b(stack_a, stack_b);
			}
			while(node->index != 0)
				rotate_both(stack_a, stack_b);
		}
		else //a alhaalla
		{
			while (find_index(*stack_a, find_nearest_bigger(stack_a, node->num)) != 0)
				reverse_rotate_a(stack_a, stack_b);
			while(node->index != 0)
				rotate_b(stack_a, stack_b);
		}
		push_b_to_a(stack_a, stack_b);
	}

}*/
