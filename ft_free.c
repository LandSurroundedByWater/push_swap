/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:58:55 by tsaari            #+#    #+#             */
/*   Updated: 2024/01/19 14:02:53 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstdelone(t_stack *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	(del)(&(lst->num));
	(del)(&(lst->index));
	free(lst);
}

void	ft_lstclear(t_stack **lst, void (*del)(void *))
{
	t_stack	*temp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
	*lst = 0;
}

void	*ft_free(t_stack **ptr, t_stack **ptr2)
{
	if (ptr != NULL && *ptr != NULL)
	{
		ft_lstclear(ptr, &free);
		exit(1);
	}
	if (ptr2 != NULL && *ptr2 != NULL)
	{
		ft_lstclear(ptr2, &free);
		exit (1);
	}
	exit (1);
}