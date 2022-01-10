/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:39:57 by shocquen          #+#    #+#             */
/*   Updated: 2022/01/10 18:36:05 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_3(int *a, int *b, int *c, t_list *s)
{
	*a = s->content;
	*b = s->next->content;
	*c = s->next->next->content;
}

int	ps_sort_3(t_list **s)
{
	int	a;
	int	b;
	int	c;

	set_3(&a, &b, &c, (*s));
	if (a < b && a < c && b > c)
	{
		swap((*s), 'a');
		rotate((*s), 'a');
	}
	else if (a < b && a > c && b > c)
		rrotate(s, 'a');
	else if (a > b && a < c && b < c)
		swap((*s), 'a');
	else if (a > b && a > c && b > c)
	{
		swap((*s), 'a');
		rrotate(s, 'a');
	}
	else
		rotate((*s), 'a');
	return (3);
}