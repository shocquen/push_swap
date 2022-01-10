/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:38:10 by shocquen          #+#    #+#             */
/*   Updated: 2022/01/10 16:33:09 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>
int	ps_sort(t_list **s)
{
	if (!is_sorted((*s)) || ft_lstsize((*s)) == 1)
		return (0);
	if (ft_lstsize((*s)) == 2)
		swap((*s), 'a');
	if (ft_lstsize((*s)) == 3)
		ps_sort_3(s);
	return (0);
}