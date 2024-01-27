/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 07:45:23 by tsaari            #+#    #+#             */
/*   Updated: 2024/01/27 09:24:44 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_one_str(t_stack **stack_a, char **buff)
{
	int		i;
	int		index;
	int		order;
	long	num;
	t_stack	*new;

	order = -1;
	i = 0;
	index = 0;
	while (buff[i] != 0)
	{
		num = ft_atol(buff[i]);
		if (num > 2147483647 || num < -2147483648)
		{
			ft_free(stack_a);
			ft_error();
		}
		new = ft_lstnew_ps(num, index, order);
		if (!new)
			ft_free(stack_a);
		check_dublicates(*stack_a, new);
		ft_lstadd_back_ps(stack_a, new);
		index++;
		i++;
	}
}

void	parse_argv(t_stack **stack_a, int argc, char **argv)
{
	int		i;
	int		index;
	int		order;
	long	num;
	t_stack	*new;

	i = 1;
	index = 0;
	order = -1;
	while (i < argc)
	{
		num = ft_atol(argv[i]);
		if (num > 2147483647 || num < -2147483648)
		{
			ft_free(stack_a);
			ft_error();
		}
		new = ft_lstnew_ps(num, index, order);
		if (!new)
			ft_free(stack_a);
		check_dublicates(*stack_a, new);
		ft_lstadd_back_ps(stack_a, new);
		index++;
		i++;
	}
}

void	ft_free_buff(char **s)
{
	size_t	i;

	i = 0;
	if (!s)
		exit(1);
	while (s[i] != '\0')
	{
		free (s[i]);
		i++;
	}
	free(s);
}

void	parse_stack_a(char **argv, int argc, t_stack **stack_a)
{
	int		i;
	char	**buff;

	i = 0;
	if (argc == 2)
	{
		buff = ft_split(argv[1], ' ');
		while (buff[i] != 0)
		{
			check_isdigit(buff[i]);
			i++;
		}
		parse_one_str(stack_a, buff);
		ft_free_buff(buff);
	}
	else
	{
		i = 1;
		while (argv[i] != 0)
		{
			check_isdigit(argv[i]);
			i++;
		}
		parse_argv(stack_a, argc, argv);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

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
	exit (0);
}
