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
	ft_printf("a: ");
	ft_lstiter(stack_a, &printcnt);

	/* Swap test */
	swap(stack_a);
	/* Print lst */
	YELL("sa");
	ft_printf("a: ");
	ft_lstiter(stack_a, &printcnt);

	/* Push b test */
 	YELL("pb");
	push(&stack_a, &stack_b);
	ft_printf("a: ");
	ft_lstiter(stack_a, &printcnt);
	ft_printf("\nb: ");
	ft_lstiter(stack_b, &printcnt);

	/* Rotate a test */
	YELL("ra");
	rotate(stack_a);
	ft_printf("a: ");
	ft_lstiter(stack_a, &printcnt);

	/* Rotate b test */
	YELL("rb");
	rotate(stack_b);
	ft_printf("b: ");
	ft_lstiter(stack_b, &printcnt);

	/* RRotate a test */
	YELL("rra");
	rrotate(&stack_a);
	ft_printf("a: ");
	ft_lstiter(stack_a, &printcnt);
}