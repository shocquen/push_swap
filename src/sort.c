/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:38:10 by shocquen          #+#    #+#             */
/*   Updated: 2022/01/10 18:34:01 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>
int	ps_sort(t_list **s, int c)
{
	int	i;

	i = 0;
	if (!is_sorted((*s)) || ft_lstsize((*s)) == 1)
		return (i);
	else if (ft_lstsize((*s)) == 2)
		i = swap((*s), c);
	else if (ft_lstsize((*s)) == 3)
		i = ps_sort_3(s);
	else if (ft_lstsize((*s)) <= 5)
		i = ps_sort_5(s);
	return (i);
}