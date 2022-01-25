/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:57:38 by shocquen          #+#    #+#             */
/*   Updated: 2022/01/25 11:34:40 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	lowest_to_top(t_list **a, t_list **b, t_list **actions)
{
	int i;

	i = get_lowest((*a));
	if (i == 0)
		push(a, b, actions, -1);
	else if (i == 1)
	{
		swap((*a), actions, 1);
		push(a, b, actions, -1);
	}
	else if (i == 2)
	{
		rrotate(a, actions, 1);
		rrotate(a, actions, 1);
		push(a, b, actions, -1);
	}
	else if (i == 3)
	{
		rrotate(a, actions, 1);
		push(a, b, actions, -1);
	}
}

int	ps_sort_4(t_list **a, t_list **b, t_list **actions)
{
	lowest_to_top(a, b, actions);
	ps_sort(a, actions, 1);
	push(b, a, actions, 1);
	ft_lstclear(b);
	return (1);
}