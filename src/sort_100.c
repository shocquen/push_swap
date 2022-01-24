/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 10:29:58 by shocquen          #+#    #+#             */
/*   Updated: 2022/01/24 17:49:05 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

 

/* Return the index of lightest nb in a chunk*/

/* int	get_lightest(t_list *lst, int min, int max)
{
	int	i;
	int	ret;
	int	tmp;
	int	size;
	int	weight;

	i = 0;
	size = ft_lstsize(lst);
	tmp = size;
	while (lst)
	{
		if (lst->content >= min && lst->content < max)
		{
			if (i > size / 2)
				weight = size - 1 - i;
			else
				weight = i;
			if (tmp > weight)
			{
				ret = lst->content;
				tmp = weight;
			}
		}
		lst = lst->next;
		i++;
	}
	return (ret);
} */

/* static int *get_chunks(t_list *s, int i)
{
	int chunks[i + 1];
	int	j;
	int	min;
	int	max;
	int	delta;

	j = 0;
	while (j < i)
	{
		chunks[j]= 0;
		j++;
	}
} */

/* static void	push_lighest(t_list **a, t_list **b, int c)
{
	int	size;
	int	i;

	i = get_index((*a), c);
	size = ft_lstsize(*a);
	if (i == -1)
		return ;
	else if (i > 0)
		{
			if (i <= size / 2)
				rotate((*a), 'a');
			else
				rrotate(a, 'a');
		}
	push(a, b, 'b');
} */

/* static void	push_lowest(t_list **a, t_list **b, t_list **actions)
{
	int	size;

	size = ft_lstsize(*a);
	while (get_lowest(*a))
		{
			if (get_lowest(*a) <= size / 2)
				rotate((*a), actions, 1);
			else
				rrotate(a, actions, 1);
		}
	push(a, b, actions, -1);
}

int	ps_sort_100(t_list **a, t_list **b, t_list **actions)
{
	while (*a)
		push_lowest(a, b, actions);
	while (*b)
		push(b, a, actions, 0);
	ptest((*a), "\na: ");
	return(0);
} */

/* int	ps_sort_100(t_list **a, t_list **b, t_list **actions)
{
	(void)b;
	(void)actions;
	int i = 0;
	while (i++ < 6)
	{
		ft_printf("index of %d is %d\n", (*a)->content, (*a)->index);
		rotate((*a), actions, 0);
	}
	return (0);
} */

int	ps_sort_100(t_list **a, t_list **b, t_list **actions)
{
	int	size;
	int	i;
	int	j;
	int	n;

	size = ft_lstsize(*a);
	i = 0;
	while (is_sorted(*a))
	{
		j = -1;
		while (++j < size)
		{
			// ptest((*a), "\na: ");
			n = (*a)->index;
			if ((n >> i) & 1)
				rotate((*a), actions, 1);
			else
				push(a, b, actions, -1);
		}
		while(*b)
			push(b, a, actions, 1);
		++i;
	}
	return(0);
}
