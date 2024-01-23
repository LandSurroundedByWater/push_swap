#include "push_swap.h"

void	printnode(t_stack *node)
{
	printf("Number---> %d\n", node->num);
	printf("Index---> %d\n", node->index);
	printf("Order---> %d\n", node->order);
	printf("Flag---> %d\n", node->flag);
	printf("Cost---> %d\n", node->cost);
}

void	ft_lstiter_ps(t_stack *stack, void (*f)(t_stack *))
{
	t_stack *temp;

	if (!stack && !f)
		return ;
	temp = stack;
	while (temp != NULL)
	{
		f(temp);
		temp = temp->next;
	}
}