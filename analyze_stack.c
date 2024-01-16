
#include"push_swap.h"

t_stack	*lowest_order(t_stack **stack)
{
	t_stack *temp;
	int		lowest;

	lowest = INT_MAX;
	if (!stack)
		exit (1);
	temp = *stack;
	while (temp != 0)
	{
		if (temp->num <= lowest && temp->order == -1)
			lowest = temp->num;
		temp = temp->next;
	}
	temp = *stack;
	while (temp->num != lowest)
		temp = temp->next;
	return (temp);
}
void set_order(t_stack **stack)
{
    int order;

    order = 1;
    while(order <= ft_lstsize(*stack))
    {
        lowest_order(stack)->order = order;
        order++;
    }
}
