/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 17:02:47 by shocquen          #+#    #+#             */
/*   Updated: 2022/01/10 18:47:30 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_sort_5(t_list **s)
{
	t_list	*b;
	int		c;

	b = NULL;
	push(s, &b, 'b');
	push(s, &b, 'b');
	c = ps_sort(s, 0);
	if (!is_sorted(b))
	{
		c += swap(b, c);
		c++;
	}
	if (c == 3)
		ft_printf("ss\n");
	else if (c == 1)
		ft_printf("sa\n");
	else
		ft_printf("sb\n");
	push(&b, s, 'a');
	ps_sort(s, 'a');	
	push(&b, s, 'a');
	if (is_sorted((*s)))
		swap((*s), 'a');
	return (5);
}
