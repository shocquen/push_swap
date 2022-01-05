#include "push_swap.h"

#define YELL(txt)		(ft_printf("\n–––––––––– %s ––––––––––\n", txt))

static void printcnt(int c)
{
	ft_printf("> %d ", (char)c);
}


int	main(void)
{
	t_list	*stack_a;
	t_list	*stack_b = NULL;

	/* Init and set stacks */
	stack_a= ft_lstnew(0);
	for (int i = 1; i < 10; i++)
		ft_lstadd_back(&stack_a, ft_lstnew(i));

	/* Print lst */
	YELL("the stack");
	ft_lstiter(stack_a, &printcnt);

	/* Swap test */
	swap(stack_a);
	/* Print lst */
	YELL("sa");
	ft_lstiter(stack_a, &printcnt);

/* 	YELL("del one");
	stack_b = stack_a->next;
	ft_lstdelone(stack_a);
	stack_a = stack_b;
	ft_lstiter(stack_a, &printcnt); */


	/* Push b test */
 	YELL("pb");
	push(stack_a, stack_b);
/* 	ft_lstiter(stack_a, &printcnt);
	ft_lstiter(stack_b, &printcnt); */
	// ft_lstiter(stack_b, &printcnt, 'L');
	// show_stacks(stack_a, stack_b);
}