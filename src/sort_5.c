/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 17:02:47 by shocquen          #+#    #+#             */
/*   Updated: 2022/01/10 23:05:14 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_sort_5(t_list **s)
{
	t_list	*b;
	int		c[2];

	*(long *)c = 0;
	b = NULL;
	push(s, &b, 'b');
	push(s, &b, 'b');
	c[0] = ps_sort(s, 0);
	// if (!is_sorted((*s)) && get_lowest(b))
	// 	c[0] = swap((*s), 0);
	if (!is_sorted(b) && get_lowest(b))
		c[1] = swap(b, 0);
	if (c[0] && c[1])
		ft_printf("ss\n");
	else if (c[0] && !c[1])
		ft_printf("sa\n");
	else if (!c[0] && c[1])
		ft_printf("sb\n");
	push(&b, s, 'a');
	ps_sort(s, 'a');	
	push(&b, s, 'a');
	if (is_sorted((*s)) && get_hiest(*s) != 0)
		swap((*s), 'a');
	else if (is_sorted((*s)))
		rotate(*(s), 'a');
	return (1);
}
