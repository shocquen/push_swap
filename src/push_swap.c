/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:15:13 by shocquen          #+#    #+#             */
/*   Updated: 2022/01/10 23:05:34 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* static void	pcontent(int c)
{
	ft_printf("> %d ", (char)c);
} */

static void	show_error(t_list **l, int free)
{
	write(STDERR_FILENO, "Error\n", 6);
	if (free == 1)
		ft_lstclear(l);
	exit(1);
}

static void	parse_str(char **argv, t_list	**stack, int argc)
{
	char	**args;
	int			i;

	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		i = -1;
		while (args[++i])
		{
			if (!check_d(args[i]))
				ft_lstadd_back(stack, ft_lstnew(ft_atoi(args[i])));
			else
				show_error(stack, 1);
		}
	}
	else
	{
		i = 0;
		while (argc > ++i)
			if (!check_d(argv[i]))
				ft_lstadd_back(stack, ft_lstnew(ft_atoi(argv[i])));
			else
				show_error(stack, 1);
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	
	if(argc < 2)
		return (0);
	parse_str(argv, &stack_a, argc);
	if (check_dbl(stack_a))
		show_error(&stack_a, 1);
	ps_sort(&stack_a, 0);
	
	/* TEST PART*/
	// ft_printf("lowst b: %d\n", get_lowest(stack_a));
	// ft_printf("\nstack_a: ");
	// ft_lstiter(stack_a, &pcontent);
	// ft_printf("\n");
	// ft_printf("sorted ? %s\n", is_sorted(stack_a) ? "Nope." : "YEAH!");
	return (0);
}
