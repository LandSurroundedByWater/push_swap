/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:05:56 by tsaari            #+#    #+#             */
/*   Updated: 2024/01/19 14:39:17 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void initializeStacks(stacks *stacks)
{
    stacks->stack_a = NULL;
    stacks->stack_b = NULL;
}

int	converttoint(const char *str, int i, int neg)
{
	long	ret;

	ret = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		ret = (ret * 10) + str[i] - 48;
		if (ret < 0 && neg == 1)
			return ((int)LONG_MAX);
		else if (ret < 0 && neg == -1)
			return ((int)LONG_MIN);
		i++;
	}
	return (ret);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		neg;

	neg = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	else if (!(str[i] >= 48 && str[i] <= 57))
		return (0);
	return (neg * converttoint(str, i, neg));
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

void parse_stack_a(char **argv, int argc, t_stack **stack_a)
{
    int i;
	int index;
	int order;

	index = 0;
    i = 1;
    while (i < argc)
    {
		long num;
        num = ft_atoi(argv[i]);
		order = -1;
		if (num > 2147483647 || num < -2147483648)
			exit (1);
        ft_lstadd_back(stack_a, ft_lstnew(num, index, order));
		index++;
		i++;
    }
}

int main(int argc, char **argv)
{
	stacks stacks;
	t_stack *stack_a;
	t_stack *stack_b;
	t_stack *temp;

	stack_a = stacks.stack_a;
	stack_b = stacks.stack_b;
	parse_stack_a(argv, argc, &stack_a);
	set_order(&stack_a);
	flag_increasing(stack_a);
	push_not_flagged(&stack_a, &stack_b);
	reset_costs(&stack_a, &stack_b);
	sort_big(&stack_a, &stack_b);
	//sort_five(&stack_a, &stack_b);
	temp = lowest(&stack_a);
	while (temp->index != 0)
	{
		if (temp->index < ft_lstsize(stack_a) / 2)
			rotate_a(&stack_a, &stack_b);
		else
			reverse_rotate_a(&stack_a, &stack_b);
	}
	return 0;
}
