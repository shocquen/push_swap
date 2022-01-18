/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 22:08:57 by shocquen          #+#    #+#             */
/*   Updated: 2022/01/18 18:15:02 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 
	Get the index of the lowest nb
*/

int	get_lowest(t_list *s)
{
	int	i[2];
	int	low;

	*(long *)i = 0;
	low = s->content;
	while (s)
	{
		if (s)
		{
			if (low > s->content)
			{
				low = s->content;
				i[1] = i[0];
			}
		}
		s = s->next;
		i[0]++;
	}
	return (i[1]);
}

/* 
	Get the index of the hiest nb
*/

int	get_hiest(t_list *s)
{
	int	i[2];
	int	hight;

	*(long *)i = 0;
	hight = s->content;
	while (s)
	{
		if (s)
		{
			if (hight < s->content)
			{
				hight = s->content;
				i[1] = i[0];
			}
		}
		s = s->next;
		i[0]++;
	}
	return (i[1]);
}

/* 
	Get the value of an index
*/

int	get_value(t_list *s, int i)
{
	int	c;

	c = 0;
	while (s)
	{
		if (s)
		{
			if (c == i)
				return (s->content);
		}
		c++;
		s = s->next;
	}
	return (-1);
}

/* 
	Get the nb of moves needed to get a node at the top of the list
*/

int	get_weigth(t_list *s, int i)
{
	int	median;
	int	size;

	size = ft_lstsize(s);
	median = size / 2;
	if (i <= median)
		return (i);
	return (size - i);
}
