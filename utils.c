#include "push_swap.h"

t_stack	*ft_last_node(t_stack *stack)
{
	if (stack == 0)
		return (0);
	while (stack->next != 0)
		stack = stack->next;
	return (stack);
}

t_stack	*ft_second_last_node(t_stack *stack)
{
	if (stack == 0)
		return (0);
	while (stack->next->next != 0)
		stack = stack->next;
	return (stack);
}

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

int	ft_lstsize(t_stack *lst)
{
	int	size;

	size = 0;
	while (lst != 0)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

t_stack	*ft_lstnew(int num, int index, int order)
{
	t_stack	*newnode;

	newnode = (t_stack *)malloc(sizeof(*newnode));
	if (!newnode)
		return (NULL);

	newnode->num = num;
	newnode->index = index;
	newnode->order = order;
	newnode->next = NULL;
	newnode->flag = 0;
	newnode->cost = -1;
	return (newnode);
}
void	ft_lstadd_back(t_stack **stack, t_stack *newnode)
{
	t_stack *temp;

	temp = *stack;
    if (*stack == NULL)
        *stack = newnode;
    else
    {
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
		newnode->next = NULL;
    }
}