
#include "push_swap.h"

int	converttoint(const char *str, int i, int neg)
{
	long	ret;

	ret = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		ret = (ret * 10) + str[i] - 48;
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
	int		neg;

	neg = 1;
	i = 0;
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


void	update_indexes(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *temp_a;
	t_stack *temp_b;
	int newindex;

	temp_a = NULL;
	temp_b = NULL;

	if (*stack_a != NULL)
		temp_a = *stack_a;
	if (*stack_b != NULL)
		temp_b = *stack_b;
	newindex = 0;
	while (temp_a != NULL)
	{
		temp_a->index = newindex;
		temp_a = temp_a->next;
		newindex++;
	}
	newindex = 0;
	while (temp_b != NULL)
	{
		temp_b->index =  newindex;
		temp_b = temp_b->next;
		newindex++;
	}
}


void parse_stack_a(char **argv, int argc, t_stack **stack_a)
{
    int i;
	int index;
	int order;

	index = 0;
    i = 1;
    while (i < argc)
    {
		long num;
        num = ft_atoi(argv[i]);
		order = -1;
		//if (num > 2147483647 || num < -2147483648)
		//	exit (1);
        ft_lstadd_back(stack_a, ft_lstnew(num, index, order));
		index++;
		i++;
    }

}

int main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;

	stack_a = NULL;
	stack_b = NULL;

//	if (argc == 1)
//		exit(1);
	parse_stack_a(argv, argc, &stack_a);

	//give_value(stack_a);

//	printf("\n\n PARSE Stack A\n");
//	ft_lstiter(stack_a, &printnode);

	set_order(&stack_a);

//	printf("\n\n SET Stack A\n");
//	ft_lstiter(stack_a, &printnode);

	flag_increasing(stack_a);

//	printf("\n\n FLAG Stack A\n");

//	ft_lstiter(stack_a, &printnode);

	push_not_flagged(&stack_a, &stack_b);

	printf("\n\n TOB Stack A\n");
	ft_lstiter(stack_a, &printnode);

	printf("\n\n TOB Stack B\n");
	ft_lstiter(stack_b, &printnode);


	reset_costs(&stack_a, &stack_b);

	printf("\n\n PUSHED Stack A\n");
	ft_lstiter(stack_a, &printnode);

	printf("\n\n PUSHED Stack B\n");
	ft_lstiter(stack_b, &printnode);


	find_cheapest_and_push(&stack_a, &stack_b);
	//sort_five(&stack_a, &stack_b);

	printf("\n\n PUSHED BACK Stack A\n");
	ft_lstiter(stack_a, &printnode);

	printf("\n\n PUSHED BACK Stack B\n");
	ft_lstiter(stack_b, &printnode);


//	printf("\n\nStack A  %d\n", ft_lstsize(stack_a));

	//push_back_node(&stack_a, &stack_b);
	//lis_analyzer(&stack_a, &stack_b);

	return 0;
}