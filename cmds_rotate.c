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
    if (*stack == NULL || (*stack)->next == NULL)
        return ;

    t_stack *tmp1 = ft_last_node(*stack);
    t_stack *tmp2 = ft_second_last_node(*stack);
    ft_lstadd_front(stack, tmp1);
    tmp2->next = NULL;
}


void	rotate_top_to_bottom(t_stack **stack)
{
    if (*stack == NULL || (*stack)->next == NULL)
        return ;

    t_stack *tmp1 = ft_last_node(*stack);
    t_stack *tmp2 = (*stack);
    ft_lstadd_back(stack, ft_lstnew(tmp2->num, tmp2->index));
    ft_lstadd_front(stack, tmp1);
	free(tmp2);
}