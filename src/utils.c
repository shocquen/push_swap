/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 22:08:57 by shocquen          #+#    #+#             */
/*   Updated: 2022/01/10 22:45:04 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_lowest(t_list *s)
{
	int	i;
	int	low;

	i = -1;
	low = s->content;
	while (s)
	{
		s = s->next;
		if (s)
		{
			if (low > s->content)
				low = s->content;
		}
		i++;
	}
	return (i);
}

int	get_hiest(t_list *s)
{
	int	i;
	int	low;

	i = -1;
	low = s->content;
	while (s)
	{
		s = s->next;
		if (s)
		{
			if (low < s->content)
				low = s->content;
		}
		i++;
	}
	return (i);
}