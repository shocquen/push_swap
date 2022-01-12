/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:38:10 by shocquen          #+#    #+#             */
/*   Updated: 2022/01/12 10:26:51 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>
int	ps_sort(t_list **s, int c)
{
	t_list	*b;
	int			i;
	int 		size;

	i = 0;
	b = NULL;
	size = ft_lstsize((*s));
	if (!is_sorted((*s)) || size == 1)
		return (i);
	else if (size == 2)
		i = swap((*s), c);
	else if (size == 3)
		i = ps_sort_3(s);
	else if (size == 4)
		i = ps_sort_4(s, &b);
	else if (size == 5)
		i = ps_sort_5(s, &b);
	else if  (size <= 100)
		i = ps_sort_100(s, &b);
	ft_lstclear(&b);
	return (i);
}