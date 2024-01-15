#include "push_swap.h"

t_stack	*ft_second_last_node(t_stack *stack)
{
	if (stack == 0)
		return (0);
	while (stack->next->next != 0)
		stack = stack->next;
	return (stack);
}
t_stack	*ft_last_node(t_stack *stack)
{
	if (stack == 0)
		return (0);
	while (stack->next != 0)
		stack = stack->next;
	return (stack);
}

void	rotate_bottom_to_top(t_stack **stack)
{
    if (*stack == NULL)
        return ;

    t_stack *tmp1 = ft_last_node(*stack);
    t_stack *tmp2 = ft_second_last_node(*stack);
    ft_lstadd_front(stack, tmp1);
    tmp2->next = NULL;
}


void	rotate_top_to_bottom(t_stack **stack)
{
    if (*stack == NULL)
        return ;

    t_stack *tmp = (*stack);
    ft_lstadd_back(stack, ft_lstnew(tmp->num, tmp->index));
	(*stack) = (*stack)->next;
	free(tmp);
}
void rotate_a(t_stack **stack_a, t_stack **stack_b)
{
	rotate_top_to_bottom(stack_a);
	update_indexes(stack_a, stack_b);
	write(1, "ra\n", 3);
}

void rotate_b(t_stack **stack_a, t_stack **stack_b)
{
	rotate_top_to_bottom(stack_b);
	update_indexes(stack_a, stack_b);
	write(1, "rb\n", 3);
}

void rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	rotate_top_to_bottom(stack_a);
	rotate_top_to_bottom(stack_b);
	update_indexes(stack_a, stack_b);
	write(1, "rr\n", 4);
}

void reverse_rotate_a(t_stack **stack_a, t_stack **stack_b)
{
	rotate_bottom_to_top(stack_a);
	update_indexes(stack_a, stack_b);
	write(1, "rra\n", 4);
}

void reverse_rotate_b(t_stack **stack_a, t_stack **stack_b)
{
	rotate_bottom_to_top(stack_b);
	update_indexes(stack_a, stack_b);
	write(1, "rrb\n", 4);
}

void reverse_rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	rotate_bottom_to_top(stack_a);
	rotate_bottom_to_top(stack_b);
	update_indexes(stack_a, stack_b);
	write(1, "rrr\n", 4);
}