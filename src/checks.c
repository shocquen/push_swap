/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:20:12 by shocquen          #+#    #+#             */
/*   Updated: 2022/01/10 15:05:03 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *s)
{
	int	c;

	while(s && s->next)
	{
		c = s->content;
		s = s->next;
		if (c > s->content)
			return (1);
	}
	return (0);
}

int	check_d(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (!ft_isdigit(str[i]))
			return (1);
	return (0);
}

int	check_dbl(t_list *s)
{
	int			c;
	t_list	*tmp;

	while (s)
	{
		c = s->content;
		tmp = s->next;
		while (tmp)
		{
			if (tmp->content == c)
				return (1);
			tmp = tmp ->next;
		}
		s = s->next;
	}
	return (0);
}
