
#include <stdio.h>
#include "push_swap.h"



/*void	give_value(t_stack *stack_a)
{
	int biggest;
	int len;

	len = 0;

	len = ft_lstsize(stack_a);
    int maxVal = stack_a->num;
    t_stack * temp = stack_a->next;

    while (temp != NULL)
	{
        if (temp->num > maxVal && temp->index == 0)
		{
            maxVal = temp->num;
			temp->index = len;
			len--;
        }
        temp = temp->next;
    }

}*/



int	converttoint(const char *str, int i, int neg)
{
	long	ret;

	ret = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		ret = ret * 10 + str[i] - 48;
		if (ret < 0 && neg == 1)
			return ((int)LONG_MAX);
		else if (ret < 0 && neg == -1)
			return ((int)LONG_MIN);
		i++;
	}
	return (ret);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	ret;
	int		neg;

	neg = 1;
	i = 0;
	ret = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	else if (!(str[i] >= 48 && str[i] <= 57))
		return (0);
	return (neg * converttoint(str, i, neg));
}

/*void	ft_lstdelone(t_stack *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	(del)(&(lst->num));
	(del)(&(lst->index));
	free(lst);
}

void	ft_lstclear(t_stack **lst, void (*del)(void *))
{
	t_stack	*temp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
	*lst = 0;
}*/


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



void	printnode(t_stack *node)
{
	printf("Number---> %d\n", node->num);
	printf("Value---> %d\n", node->index);
}


void	ft_lstiter(t_stack *lst, void (*f)(t_stack *))
{
	t_stack *temp;

	if (!lst && !f)
		return ;
	temp = lst;
	while (temp != NULL)
	{
		f(temp);
		temp = temp->next;
	}
}



t_stack	*ft_lstnew(int num, int index)
{

	t_stack	*newnode;

	newnode = (t_stack *)malloc(sizeof(*newnode));
	if (!newnode)
		return (NULL);

	newnode->num = num;
	newnode->index = index;
	newnode->next = NULL;
	return (newnode);
}
void	ft_lstadd_back(t_stack **stack, t_stack *newnode)
{
    if (*stack == NULL)
    {
        *stack = newnode;
    }
    else
    {
        t_stack *temp = *stack;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
}



void parse_stack_a(char **argv, int argc, t_stack **stack_a)
{
    int i;
	int index;

	index = 0;
    i = 1;
    while (i < argc)
    {
		int num;
        num = ft_atoi(argv[i]);
        ft_lstadd_back(stack_a, ft_lstnew(num, index));
		index++;
		i++;
    }
}

int main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;

	if (argc == 1)
		exit(1);
	parse_stack_a(argv, argc, &stack_a);
	//give_value(stack_a);
	printf("Stack A\n");
	ft_lstiter(stack_a, &printnode);
	printf("Stack A\n");
	rotate_top_to_bottom(&stack_a);

	printf("Stack A\n");
	ft_lstiter(stack_a, &printnode);

	push_a_to_b(&stack_a, &stack_b);

	printf("Stack A\n");
	ft_lstiter(stack_a, &printnode);

	printf("Stack B\n");
	ft_lstiter(stack_b, &printnode);

	rotate_bottom_to_top(&stack_a);

	printf("Stack A\n");
	ft_lstiter(stack_a, &printnode);

	push_a_to_b(&stack_a, &stack_b);

	push_a_to_b(&stack_a, &stack_b);
	printf("\nStack A\n");
	ft_lstiter(stack_a, &printnode);

	printf("\nStack B\n");
	ft_lstiter(stack_b, &printnode);
	push_b_to_a(&stack_b, &stack_a);
	printf("\nStack A\n");
	ft_lstiter(stack_a, &printnode);
	swap_a(&stack_a);
	printf("\nStack A\n");
	ft_lstiter(stack_a, &printnode);
	swap_b(&stack_b);
	printf("\n\n");
	printf("\nStack B\n");
	ft_lstiter(stack_b, &printnode);
	push_a_to_b(&stack_a, &stack_b);
	printf("\nStack A\n");
	ft_lstiter(stack_a, &printnode);
	swap_both(&stack_a, &stack_b);
	printf("\nStack A\n");
	ft_lstiter(stack_a, &printnode);
	printf("\nStack B\n");
	ft_lstiter(stack_b, &printnode);






	//printf("\nStack B\n");
	//ft_lstiter(stack_b, &printnode);
	//printf("\nStack B\n");
	//ft_lstclear(&stack_a, &free);
	return 0;
}