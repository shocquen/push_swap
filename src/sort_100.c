/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 10:29:58 by shocquen          #+#    #+#             */
/*   Updated: 2022/01/25 13:21:19 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			n = (*a)->index;
			if ((n >> i) & 1)
				rotate((*a), actions, 1);
			else
				push(a, b, actions, -1);
		}
		while (*b)
			push(b, a, actions, 1);
		++i;
	}
	return (0);
}
