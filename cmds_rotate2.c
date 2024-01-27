/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_rotate2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 20:28:40 by tsaari            #+#    #+#             */
/*   Updated: 2024/01/26 15:22:05 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_stack **stack_a, t_stack **stack_b)
{
	rotate_bottom_to_top(stack_a);
	update_indexes(stack_a, stack_b);
	write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_stack **stack_a, t_stack **stack_b)
{
	rotate_bottom_to_top(stack_b);
	update_indexes(stack_a, stack_b);
	write(1, "rrb\n", 4);
}

void	reverse_rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	rotate_bottom_to_top(stack_a);
	rotate_bottom_to_top(stack_b);
	update_indexes(stack_a, stack_b);
	write(1, "rrr\n", 4);
}
