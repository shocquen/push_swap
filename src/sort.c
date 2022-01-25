/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:38:10 by shocquen          #+#    #+#             */
/*   Updated: 2022/01/25 12:16:57 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_sort(t_list **s, t_list **actions, int c)
{
	t_list	*b;
	int		i;
	int		size;

	i = 0;
	b = NULL;
	size = ft_lstsize((*s));
	if (!is_sorted((*s)) || size == 1)
		return (i);
	else if (size == 2)
		i = swap((*s), actions, c);
	else if (size == 3)
		i = ps_sort_3(s, actions);
	else if (size == 4)
		i = ps_sort_4(s, &b, actions);
	else if (size == 5)
		i = ps_sort_5(s, &b, actions);
	else
		i = ps_sort_100(s, &b, actions);
	ft_lstclear(&b);
	return (i);
}
