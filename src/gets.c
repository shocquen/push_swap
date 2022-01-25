/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 22:08:57 by shocquen          #+#    #+#             */
/*   Updated: 2022/01/25 10:12:30 by shocquen         ###   ########.fr       */
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

/* Get the index of the node */
int	get_index(t_list *lst, t_list *node)
{
	t_list	*tmp;
	int			ret;

	tmp = lst;
	ret = 0;
	while (lst && lst->content != node->content)
		lst = lst->next;
	// if (!lst)
	// 	return (ret);
	while (tmp)
	{
		if (lst->content > tmp->content)
			ret++;
		tmp = tmp->next;
	}
	return (ret);
}
