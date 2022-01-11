/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:57:38 by shocquen          #+#    #+#             */
/*   Updated: 2022/01/11 14:16:37 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	lowest_to_top(t_list **a, t_list **b)
{
	int i;

	i = get_lowest((*a));
	if (i == 0)
		push(a, b, 'b');
	else if (i == 1)
	{
		swap((*a), 'a');
		push(a, b, 'b');
	}
	else if (i == 2)
	{
		rrotate(a, 'a');
		rrotate(a, 'a');
		push(a, b, 'b');
	}
	else if (i == 3)
	{
		rrotate(a, 'a');
		push(a, b, 'b');
	}
}

int	ps_sort_4(t_list **a, t_list **b)
{
	lowest_to_top(a, b);
	ps_sort(a, 'a');
	push(b, a, 'a');
	ft_lstclear(b);
	return (1);
}