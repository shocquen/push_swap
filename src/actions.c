/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:15:08 by shocquen          #+#    #+#             */
/*   Updated: 2022/01/18 17:36:30 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_list *s, t_list **actions, int c)
{
	int	tmp;

	if (s && s->next)
	{
		tmp = s->content;
		s->content = s->next->content;
		s->next->content = tmp;
	}
	if (c != 0)
		ft_lstadd_back(actions, ft_lstnew(c * SWAP));
	return (1);
}

int	push(t_list **s1, t_list **s2, t_list **actions, int c)
{
	t_list	*tmp_a;

	if (s1)
	{
		if (s2)
			ft_lstadd_front(s2, ft_lstnew((*s1)->content));
		tmp_a = (*s1)->next;
		ft_lstdelone(*s1);
		*s1 = tmp_a;
	}
	if (c != 0)
		ft_lstadd_back(actions, ft_lstnew(c * PUSH));

	return (1);
}

int	rotate(t_list *s, t_list **actions, int c)
{
	while (s)
	{
		swap(s, actions, 0);
		s = s->next;
	}
	if (c != 0)
		ft_lstadd_back(actions, ft_lstnew(c * ROTATE));
	return (1);
}

static int	pop(t_list **s)
{
	int		ret;
	t_list	*tmp;

	tmp = (*s);
	while (tmp && tmp->next->next)
		tmp = tmp->next;
	ret = tmp->next->content;
	ft_lstdelone(tmp->next);
	tmp->next = NULL;
	return (ret);
}

int	rrotate(t_list **s, t_list **actions, int c)
{
	int	tmp;

	tmp = pop(s);
	ft_lstadd_front(s, ft_lstnew(tmp));
	if (c != 0)
		ft_lstadd_back(actions, ft_lstnew(c * RROTATE));
	return (1);
}
