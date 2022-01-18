/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 17:02:47 by shocquen          #+#    #+#             */
/*   Updated: 2022/01/18 11:59:37 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_lowest(t_list **a, t_list **b)
{
	int	size;

	size = ft_lstsize(*a);
	while (get_lowest(*a))
		{
			if (get_lowest(*a) <= size / 2)
				rotate((*a), 'a');
			else
				rrotate(a, 'a');
		}
	push(a, b, 'b');
}

int	ps_sort_5(t_list **a, t_list **b)
{
	int	c[2];

	*(long *)c = 0;
	push_lowest(a, b);
	push_lowest(a, b);
	ps_sort(a, 'a');
	push(b, a, 'a');
	push(b, a, 'a');
	return (1);
}
