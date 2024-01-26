/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:05:56 by tsaari            #+#    #+#             */
/*   Updated: 2024/01/26 12:24:32 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_isdigit(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-')
		i++;
	if (str[i] == 0)
		ft_error();
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			ft_error();
		i++;
	}
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
		if (temp->order >= max && temp->order <= max + (ft_lstsize_ps(stack) / (ft_lstsize_ps(stack) / (div + ft_lstsize_ps(stack) / 50))))
		{
			max = temp->order;
			temp->flag = -1;
		}
		temp = temp->next;
	}
	temp = stack;
	while (temp->flag != -1)
	{
		if (temp->order >= max && temp->order <= max + (ft_lstsize_ps(stack) / (ft_lstsize_ps(stack) / (div + ft_lstsize_ps(stack) / 50))))
		{
			max = temp->order;
			temp->flag = -1;
		}
		temp = temp->next;
	}
}

void	parse_one_str(t_stack **stack_a, char **buff)
{
	int i;
	int index;
	int order;
	t_stack *new;

	i = 0;
	index = 0;
	order = -1;
	while (buff[i] != 0)
	{
		long num;
		num = ft_atol(buff[i]);
		if (num > 2147483647 || num < -2147483648)
		{
			if (stack_a != NULL)
				ft_free(stack_a);
			ft_error();
		}
		new = ft_lstnew_ps(num, index, order);
		if (!new)
			ft_free(stack_a);
		if (check_dublicates(*stack_a, new) == 0)
		{
			if (stack_a != NULL)
				ft_free(stack_a);
			ft_error();
		}
		ft_lstadd_back_ps(stack_a, new);
		index++;
		i++;
	}
	free(buff);
}

void parse_argv(t_stack **stack_a,int argc, char **argv)
{
	int i;
	int index;
	int order;
	t_stack *new;


	i = 1;
	index = 0;
	order = -1;
	i = 1;
	while (i < argc)
	{
		long num;
		num = ft_atol(argv[i]);
		if (num > 2147483647 || num < -2147483648)
		{
			if (stack_a != NULL)
				ft_free(stack_a);
			ft_error();
		}
		new = ft_lstnew_ps(num, index, order);
		if (!new)
			ft_free(stack_a);
		if (check_dublicates(*stack_a, new) == 0)
		{
			if (stack_a != NULL)
				ft_free(stack_a);
			ft_error();
		}
		ft_lstadd_back_ps(stack_a, new);
		index++;
		i++;
	}
}

void parse_stack_a(char **argv, int argc, t_stack **stack_a)
{
    int i;
	char **buff;

    i = 0;
	if (argc == 2)
	{
		buff = ft_split(argv[1], ' ');
		while(buff[i] != 0)
		{
			check_isdigit(buff[i]);
			i++;
		}
		parse_one_str(stack_a, buff);
	}
	else
	{
		i = 1;
		while(argv[i] != 0)
		{
			check_isdigit(argv[i]);
			i++;
		}
		parse_argv(stack_a, argc, argv);
	}
}

int main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;
	stack_a = NULL;
	stack_b = NULL;

	parse_stack_a(argv, argc, &stack_a);
	if (is_sorted(stack_a) == 1)
		exit(1);
	set_order(&stack_a);
	if (ft_lstsize_ps(stack_a) <= 3)
		sort_three(&stack_a, &stack_b);
	else if (ft_lstsize_ps(stack_a) <= 5)
		sort_five(&stack_a, &stack_b);
	else if (ft_lstsize_ps(stack_a) <= 15)
		sort_small(&stack_a, &stack_b);
	else
		sort_big(&stack_a, &stack_b);
	return 0;
}
