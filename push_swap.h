/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hiv.fi>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 08:56:29 by tsaari            #+#    #+#             */
/*   Updated: 2024/01/11 21:03:31 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int				num;
	int 			index;
	struct s_stack	*next;
} t_stack;

t_stack	*ft_lstnew(int num, int index);
void	push_a_to_b(t_stack **stack_a, t_stack **stack_b);
void	printnode(t_stack *node);
void	push_b_to_a(t_stack **stack_b, t_stack **stack_a);

#endif
