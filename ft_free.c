/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:58:55 by tsaari            #+#    #+#             */
/*   Updated: 2024/01/26 12:51:58 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error()
{
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_free(t_stack **stack)
{
	t_stack	*head;
	t_stack	*tmp;

	head = *stack;
	if (head != NULL)
	{
		while (head)
		{
			tmp = head;
			head = head->next;
			free(tmp);
		}
	}
}