/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:07:02 by tsaari            #+#    #+#             */
/*   Updated: 2024/01/27 07:57:48 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reset_flags(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (temp != NULL)
	{
		temp->order = 0;
		temp = temp->next;
	}
}

void	update_indexes(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;
	int		newindex;

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
		temp_b->index = newindex;
		temp_b = temp_b->next;
		newindex++;
	}
}

long	convert_to_long(const char *str, int i, int neg)
{
	long	ret;

	ret = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		ret = ret * 10 + str[i] - '0';
		if (ret < 0 && neg == 1)
			return (LONG_MAX);
		else if (ret < 0 && neg == -1)
			return (LONG_MIN);
		i++;
	}
	return (ret);
}

long	ft_atol(const char *str)
{
	int		i;
	int		neg;
	long	result;

	i = 0;
	neg = 1;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	else if (!(str[i] >= '0' && str[i] <= '9'))
		return (0);
	result = neg * convert_to_long(str, i, neg);
	if (result > LONG_MAX)
		return (LONG_MAX);
	else if (result < LONG_MIN)
		return (LONG_MIN);
	else
		return (result);
}

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
