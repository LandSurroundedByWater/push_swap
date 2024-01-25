/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:58:55 by tsaari            #+#    #+#             */
/*   Updated: 2024/01/24 12:41:25 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error()
{
	ft_putendl_fd("Error", 1);
	exit(1);
}

void	ft_lstdelone_ps(t_stack *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	(del)(&(lst->num));
	(del)(&(lst->index));
	free(lst);
}

void	ft_lstclear_ps(t_stack **lst, void (*del)(void *))
{
	t_stack	*temp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone_ps(*lst, del);
		*lst = temp;
	}
	*lst = 0;
}

void	ft_free(t_stack **stack)
{
	t_stack	*head;
	t_stack	*tmp;

	head = *stack;
	while (head)
	{
		tmp = head;
		head = head->next;

		free(tmp);
	}
	free(stack);
}