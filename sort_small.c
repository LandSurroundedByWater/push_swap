/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:06:52 by tsaari            #+#    #+#             */
/*   Updated: 2024/01/25 13:46:52 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int find_index(t_stack *stack, int targetNum)
{
    while (stack != NULL)
    {
        if (stack->num == targetNum)
        {
            return stack->index;
        }
        stack = stack->next;
    }
    return -1;
}



int is_sorted(t_stack *stack)
{
    while (stack != NULL && stack->next != NULL)
    {
        if (stack->num > stack->next->num)
            return 0;
        stack = stack->next;
    }
    return 1;
}



void sort_three(t_stack **stack_a,t_stack **stack_b)
{
	int biggest;

	if(is_sorted(*stack_a))
		return ;
	biggest = is_biggest(stack_a);
	if (biggest == 0)
		rotate_a(stack_a, stack_b);
	else if (biggest == 1)
		reverse_rotate_a(stack_a, stack_b);
	if ((*stack_a)->next->num < (*stack_a)->num)
		swap_a(stack_a, stack_b);
}
void sort_five(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *temp;

	push_a_to_b(stack_a, stack_b);
	push_a_to_b(stack_a, stack_b);
	sort_three(stack_a, stack_b);
	while (ft_lstsize_ps(*stack_b) != 0)
	{
		find_cheapest_and_push(stack_a, stack_b);
	}
	temp = lowest(stack_a);
	while (temp->index != 0)
	{
		if (temp->index < ft_lstsize_ps(*stack_a) / 2)
			rotate_a(stack_a, stack_b);
		else
			reverse_rotate_a(stack_a, stack_b);
	}
}

void sort_small(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *temp;

	temp = *stack_a;
	while(ft_lstsize_ps(*stack_a) > 3)
	{
		if ((*stack_a)->order == ((*stack_a)->next->order + 1))
			swap_a(stack_a, stack_b);
		if (is_sorted(*stack_a) == 1)
			break ;
		push_a_to_b(stack_a, stack_b);
	}
	if (ft_lstsize_ps(*stack_a) == 3)
		sort_three(stack_a, stack_b);
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
