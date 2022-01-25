/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:15:13 by shocquen          #+#    #+#             */
/*   Updated: 2022/01/25 11:45:39 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Set index of each node */
/* static t_list	*set_indexes(t_list *lst)
{
	t_list	*new_lst;
	t_list	*new;
	t_list	*tmp;

	if (!lst)
		return (NULL);
	new_lst = NULL;
	tmp = lst;
	while (lst)
	{
		new = ft_lstnew(lst->content, lst->index);
		if (!new)
		{
			ft_lstclear(&new_lst);
			return (NULL);
		}
		new->index = get_index(tmp, new);
		ft_lstadd_back(&new_lst, new);
		lst = lst->next;
	}
	return (new_lst);
} */

static void	set_indexes(t_list **lst)
{
	t_list	*tmp;

	if (!lst)
		return ;
	tmp = *lst;
	while (*lst)
	{
		(*lst)->index = get_index(tmp, (*lst));
		*lst = (*lst)->next;
	}
	*lst = tmp;
}

static void free2d(char **arr)
{
	int	i;

	i = -1;
	while(arr[++i])
		free(arr[i]);
	free(arr);
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
				ft_lstadd_back(stack, ft_lstnew(ft_atoi(args[i]), -1));
			else
				show_error(stack, 1);
		}
		free2d(args);
	}
	else
	{
		i = 0;
		while (argc > ++i)
			if (!check_d(argv[i]))
				if  (!ft_strlen(argv[i]))
					show_error(stack, 1);
				else
					ft_lstadd_back(stack, ft_lstnew(ft_atoi(argv[i]), -1));
			else
				show_error(stack, 1);
	}
	set_indexes(stack);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*actions;
	
	stack_a = NULL;
	actions = NULL;
	if(argc < 1)
		return (0);
	parse_str(argv, &stack_a, argc);
	if (check_dbl(stack_a))
		show_error(&stack_a, 1);
	ps_sort(&stack_a, &actions, 1);
	pactions(&actions);

	/* TEST PART*/
	// ptest(stack_a, "\na: ");
	// ft_printf("Is %s sorted in %d action(s)\n",
	// 	is_sorted(stack_a) ? "not" : "",
	// 	ft_lstsize(actions));

	ft_lstclear(&stack_a);
	ft_lstclear(&actions);
	return (0);
}
