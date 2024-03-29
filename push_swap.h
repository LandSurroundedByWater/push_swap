/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaari <tsaari@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 08:56:29 by tsaari            #+#    #+#             */
/*   Updated: 2024/01/29 10:29:11 by tsaari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	int				num;
	int				index;
	int				order;
	int				flag;
	int				cost;
	struct s_stack	*next;
}	t_stack;

int		is_biggest(t_stack **stack);
void	update_indexes(t_stack **stack_a, t_stack **stack_b);
int		is_sorted(t_stack *stack);
void	push_not_flagged(t_stack **stack_a, t_stack **stack_b);
void	set_order(t_stack **stack);
void	count_costs_to_top(t_stack **stack_a, t_stack **stack_b);
void	reset_costs(t_stack **stack_a, t_stack **stack_b);
void	find_cheapest_and_push(t_stack **stack_a, t_stack **stack_b);
void	flag_increasing(t_stack *stack);
void	check_dublicates(t_stack *stack_a, t_stack *new);
long	ft_atol(const char *str);
void	check_isdigit(char *str);
void	ft_free(t_stack **stack);
void	ft_error(void);

t_stack	*ft_lstnew_ps(int num, int index, int order);
int		ft_lstsize_ps(t_stack *stack);
void	ft_lstadd_front_ps(t_stack **stack, t_stack *new);
void	ft_lstadd_back_ps(t_stack **stack, t_stack *newnode);
t_stack	*ft_last_node(t_stack *stack);
t_stack	*ft_second_last_node(t_stack *stack);
t_stack	*lowest(t_stack **stack);
t_stack	*find_nearest_bigger(t_stack **stack, int num);

void	mv_l_and_h(t_stack **st_a, t_stack **st_b, t_stack *n_a, t_stack *n_b);
void	mv_high_nds(t_stack **st_a, t_stack **st_b, t_stack *n_a, t_stack *n_b);
void	mv_sm_nds(t_stack **st_a, t_stack **st_b, t_stack *n_a, t_stack *n_b);

void	push_a_to_b(t_stack **stack_a, t_stack **stack_b);
void	push_b_to_a(t_stack **stack_b, t_stack **stack_a);
void	swap_a(t_stack **stack_a, t_stack **stack_b);

void	rotate_a(t_stack **stack_a, t_stack **stack_b);
void	rotate_b(t_stack **stack_a, t_stack **stack_b);
void	rotate_both(t_stack **stack_a, t_stack **stack_b);
void	reverse_rotate_a(t_stack **stack_a, t_stack **stack_b);
void	reverse_rotate_b(t_stack **stack_a, t_stack **stack_b);
void	reverse_rotate_both(t_stack **stack_a, t_stack **stack_b);

void	sort_three(t_stack **stack, t_stack **stack_b);
void	sort_five(t_stack **stack_a, t_stack **stack_b);
void	sort_small(t_stack **stack_a, t_stack **stack_b);
void	sort_big(t_stack **stack_a, t_stack **stack_b);

#endif
