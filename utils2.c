#include "push_swap.h"

int lowest(t_stack **stack)
{
	t_stack *temp;
	int		lowest;

	lowest = (*stack)->num;
	if (!stack)
		exit (1);
	temp = *stack;
	while (temp != NULL)
	{
		if (temp->num < lowest)
			lowest = temp->num;
		temp = temp->next;
	}
	return (lowest);
}

int is_biggest(t_stack **stack)
{
	t_stack *temp;
	int		biggest;
	int		index;

	biggest = (*stack)->num;
	index	= (*stack)->index;

	if (!stack)
		exit (1);
	temp = *stack;
	while (temp != NULL)
	{
		if (temp->num > biggest)
		{
			biggest = temp->num;
			index	= temp->index;
		}
		temp = temp->next;
	}
	return (index);
}