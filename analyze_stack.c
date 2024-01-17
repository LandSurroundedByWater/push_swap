
#include"push_swap.h"

t_stack	*lowest_order(t_stack **stack)
{
	t_stack *temp;
	t_stack *lowestnode = NULL;
	int		lowest;

	lowest = INT_MAX;
	if (!stack)
		exit (1);
	temp = *stack;
	while (temp != 0)
	{
		if (temp->order == -1 && temp->num < lowest)
		{
			lowest = temp->num;
			lowestnode = temp;
		}
		temp = temp->next;
	}
	return (lowestnode);
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


void	flag_increasing(t_stack **stack)
{
	t_stack *temp;
	int max;

	if (!stack)
		return ;

	max = 1;
	temp = *stack;
	while (temp->order != 1)
		temp = temp->next;
	while (temp != NULL)
	{
		if (temp->order >= max && temp->order <= max + (ft_lstsize(*stack) / 8))
		{
			max = temp->order;
			temp->flag = -1;
		}
		temp = temp->next;
	}
	temp = *stack;
	while (temp->flag != -1)
	{
		if (temp->order >= max && temp->order <= max + (ft_lstsize(*stack) / 8))
		{
			max = temp->order;
			temp->flag = -1;
		}
		temp = temp->next;
	}
}

void	flag_biggest_and_lowest(t_stack **stack)
{
	t_stack *temp;
	int 	half;

	if (!stack)
		return ;
	temp = *stack;
	half = ft_lstsize(*stack) / 2;

	while (temp != NULL)
	{
		if (temp->order < (half / 2) && temp->flag != -1)
			temp->flag = 1;
		else  if (temp->order < (ft_lstsize(*stack) / 2) && temp->flag != -1)
			temp->flag = 2;
		else if (temp->order < (ft_lstsize(*stack) - (half / 2)) && temp->flag != -1)
			temp->flag = 3;
		else if (temp->order <= (ft_lstsize(*stack)) && temp->flag != -1)
			temp->flag = 4;

		temp = temp->next;
	}
}