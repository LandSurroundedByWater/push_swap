# include "push_swap.h"

int find_next_bigger(t_stack **stack, int num)
{
	t_stack *temp;
	int		nearest_bigger;
	int		index;

	nearest_bigger = (*stack)->num;
	index	= (*stack)->index;

	if (!stack)
		exit (1);
	temp = *stack;
	while (temp != NULL)
	{
		if (nearest_bigger > num)
			return (nearest_bigger);
		else
		{
			nearest_bigger = temp->num;
			index	= temp->index;
		}
		temp = temp->next;
	}
	return (num);
}

int is_sorted(t_stack *stack)
{
	int i;

	i = 0;
	while (stack->next != NULL)
	{
		if (stack->num > stack->next->num)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void sort_three(t_stack **stack_a,t_stack **stack_b)
{
	int biggest;

	if (is_sorted(*stack_a) == 1)
		exit (1);
	if (*stack_a == NULL)
		return ;
	biggest = is_biggest(stack_a);
	if (biggest == 0)
		rotate_a(stack_a, stack_b);
	else if (biggest == 1)
		reverse_rotate_a(stack_a, stack_b);
	if ((*stack_a)->next->num < (*stack_a)->num)
		swap_a(stack_a, stack_b);
}
void sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int target;
	int i;
	i = 0;

	if (is_sorted(*stack_a) == 1)
		exit (1);
	printf("p\n");
	push_a_to_b(stack_a, stack_b);
	printf("p\n");
	push_a_to_b(stack_a, stack_b);

	sort_three(stack_a, stack_b);
	printf("\nA\n");
	ft_lstiter(*stack_a, &printnode);
	printf("\nB\n");
	ft_lstiter(*stack_b, &printnode);
	printf("move back\n");
	target = find_next_bigger(stack_a, (*stack_b)->num);
	while (stack_b != NULL)
	{
		if (target == (*stack_b)->num)
		{
			push_b_to_a(stack_a, stack_b);
			rotate_a(stack_a, stack_b);
		}

		if (target <= ((ft_last_node(*stack_a))->index / 2))
		{
				while ((*stack_a)->num != target)
					rotate_a(stack_a, stack_b);
		}
		else
		{
			while ((*stack_a)->num != target)
				reverse_rotate_a(stack_a, stack_b);
		}
		push_b_to_a(stack_a, stack_b);
	}

	printf("\nA\n");
	ft_lstiter(*stack_a, &printnode);
	printf("\nB\n");
	ft_lstiter(*stack_b, &printnode);

}