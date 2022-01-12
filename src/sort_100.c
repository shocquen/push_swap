/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 10:29:58 by shocquen          #+#    #+#             */
/*   Updated: 2022/01/12 10:31:10 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_sort_100(t_list **a, t_list **b)
{
	int		c[2];

	*(long *)c = 0;
	push(a, b, 'b');
	push(a, b, 'b');
	ps_sort(a, 'a');
	// ptest((*a), "a: ");
	// ptest((*b), "b: ");
	push(b, a, 'a');
	if (!get_hiest(*a))
		rotate((*a), 'a');
	push(b, a, 'a');
	return (1);
}
