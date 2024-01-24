/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:05:56 by tsaari            #+#    #+#             */
/*   Updated: 2024/01/24 06:44:54 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void initializeStacks(stacks *stacks)
{
    stacks->stack_a = NULL;
    stacks->stack_b = NULL;
}

void	flag_increasing(t_stack *stack)
{
	t_stack *temp;
	int max;
	int div;

	div = 1;
	max = 1;
	while (div * div <= ft_lstsize_ps(stack))
		div++;
	temp = stack;
	while (temp->order != 1)
		temp = temp->next;
	while (temp != NULL)
	{
		if (temp->order >= max && temp->order <= max + (ft_lstsize_ps(stack) / div + ft_lstsize_ps(stack) / 50))
		{
			max = temp->order;
			temp->flag = -1;
		}
		temp = temp->next;
	}
	temp = stack;
	while (temp->flag != -1)
	{
		if (temp->order >= max && temp->order <= max + (ft_lstsize_ps(stack) / div + ft_lstsize_ps(stack) / 50))
		{
			max = temp->order;
			temp->flag = -1;
		}
		temp = temp->next;
	}
}

void parse_stack_a(char **argv, int argc, t_stack **stack_a)
{
    int i;
	int index;
	int order;
	t_stack *new;

	index = 0;
    i = 1;
    while (i < argc)
    {
		long num;
        num = ft_atoi(argv[i]);
		order = -1;
		if (num > 2147483647 || num < -2147483648)
			exit (1);
		new = ft_lstnew_ps(num, index, order);
		if (!new)
			exit(1);
        ft_lstadd_back_ps(stack_a, new);
		index++;
		i++;
    }
}

int main(int argc, char **argv)
{
	
	t_stack *stack_a;
	t_stack *stack_b;


	stack_a = NULL;
	stack_b = NULL;
	parse_stack_a(argv, argc, &stack_a);

	
	set_order(&stack_a);
	flag_increasing(stack_a);
	
	push_not_flagged(&stack_a, &stack_b);
	
	ft_lstiter_ps(stack_a, &printnode);
	printf("\n");
	ft_lstiter_ps(stack_b, &printnode);
	
	reset_costs(&stack_a, &stack_b);

	
	sort_big(&stack_a, &stack_b);
	
	
	
	
	//sort_five(&stack_a, &stack_b);

	
	
	return 0;
}
