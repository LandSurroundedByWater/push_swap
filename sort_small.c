# include "push_swap.h"

int find_index(t_stack *stack, int targetNum)
{
    while (stack != NULL)
    {
        if (stack->num == targetNum)
        {
            return stack->index;
        }
        stack = stack->next;
    }
    return -1;
}

int find_nearest_bigger(t_stack **stack, int num)
{
    t_stack *temp;
    int nearest_bigger;

    if (!*stack)
        exit(1);

    temp = *stack;
    nearest_bigger = INT_MAX;

    while (temp != NULL)
    {
        if (temp->num > num && temp->num < nearest_bigger)
            nearest_bigger = temp->num;

        temp = temp->next;
    }

    return nearest_bigger;
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
		return;
	if (*stack_a == NULL)
		return;
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
	if (is_sorted(*stack_a) == 1)
		exit (1);
	push_a_to_b(stack_a, stack_b);
	push_a_to_b(stack_a, stack_b);
	sort_three(stack_a, stack_b);
	while (*stack_b != NULL)
	{
		int x = find_nearest_bigger(stack_a, (*stack_b)->num);
		if (find_index(*stack_a, x) <= 1)
		{
			while((*stack_a)->num != x)
				rotate_a(stack_a, stack_b);
			push_b_to_a(stack_a, stack_b);
		}
		else
		{
			while((*stack_a)->num != x)
				reverse_rotate_a(stack_a, stack_b);
			push_b_to_a(stack_a, stack_b);
		}
	}
	if (find_index(*stack_a, lowest(stack_a)) >= 2)
	{
		while((*stack_a)->num != lowest(stack_a))
			reverse_rotate_a(stack_a, stack_b);
	}
	else
	{
		while((*stack_a)->num != lowest(stack_a))
			rotate_a(stack_a, stack_b);
	}
}
