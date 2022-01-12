/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:15:13 by shocquen          #+#    #+#             */
/*   Updated: 2022/01/12 16:42:38 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

	if (argc == 1)
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
				if  (!ft_strlen(argv[i]))
					show_error(stack, 1);
				else
					ft_lstadd_back(stack, ft_lstnew(ft_atoi(argv[i])));
			else
				show_error(stack, 1);
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	
	stack_a = NULL;
	if(argc < 1)
		return (0);
	parse_str(argv, &stack_a, argc);
	if (check_dbl(stack_a))
		show_error(&stack_a, 1);
	ps_sort(&stack_a, 0);
	
	/* TEST PART*/
	// ptest(stack_a, "\na: ");
	// ft_printf("sorted ? %s\n", is_sorted(stack_a) ? "Nope." : "YEAH!");

	ft_lstclear(&stack_a);
	return (0);
}
