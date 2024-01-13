#include "push_swap.h"

void	ft_lstadd_front(t_stack **stack, t_stack *new)
{

	if (*stack == 0)
	{
		*stack = new;
		return ;
	}
	new->next = *stack;
	*stack = new;
}


void push_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *tmp;
	t_stack *new;

	if (*stack_a == NULL)
		return;
	tmp = *stack_a;
	new = ft_lstnew((*stack_a)->num, (*stack_a)->index);
	if (!new)
		exit(1);
	ft_lstadd_front(stack_b, new);
	*stack_a = (*stack_a)->next;
	free(tmp);
	update_indexes(stack_a, stack_b);
	write(1, "pb\n", 3);
}

void	push_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *tmp;
	t_stack *new;

	if ((*stack_b)->next == NULL)
		return;
	tmp = *stack_b;
	new = ft_lstnew((*stack_b)->num, (*stack_b)->index);
	if (!new)
		exit(1);
	ft_lstadd_front(stack_a, new);
	*stack_b = (*stack_b)->next;
	free(tmp);
	update_indexes(stack_a, stack_b);
	write(1, "pa\n", 3);
}
