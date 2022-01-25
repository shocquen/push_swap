/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 17:02:47 by shocquen          #+#    #+#             */
/*   Updated: 2022/01/25 12:17:28 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_lowest(t_list **a, t_list **b, t_list **actions)
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

int	ps_sort_5(t_list **a, t_list **b, t_list **actions)
{
	int	c[2];

	*(long *)c = 0;
	push_lowest(a, b, actions);
	push_lowest(a, b, actions);
	ps_sort(a, actions, 1);
	push(b, a, actions, 1);
	push(b, a, actions, 1);
	return (1);
}
