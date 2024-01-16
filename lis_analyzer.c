#include"push_swap.h"


int lis_analyzer(t_stack **stack, t_stack **stack_b)
{
    int n;
	t_stack *lis;
	int i;
	int j;
	int max;
	t_stack *temp;


	n = ft_lstsize(*stack);
	lis = NULL;
	i = 0;
	j = 0;
	max = 0;
	t_stack *lis2;

	temp = *stack;
    lis = malloc(n * sizeof(t_stack));

	ft_lstiter(*stack, &printnode);
	while ((*stack)->order != 1)
		rotate_a(stack, stack_b);

	printf("\n\n\n");

	ft_lstiter(*stack, &printnode);


	printf("\n\n\n");
	lis = temp;
	lis2 = lis;
	max = temp->num;
	while(temp != 0)
	{

		if (temp->num > max)
		{
			lis = temp;
			max = temp->num;
			printf("MAX = %d", max);
		}
		temp = temp->next;
		
	}
	printf("LIS\n");
	ft_lstiter(lis2, &printnode);

	/*while (lis != 0)
	{
		if(max < (lis->num))
		max = lis->num;
		lis = lis->next;
	}
    printf("Length of LIS is %d\n",max);
    // Find maximum LIS value
*/
    return 0;
}
