/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:15:08 by shocquen          #+#    #+#             */
/*   Updated: 2022/01/25 11:32:08 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_list *s, t_list **actions, int c)
{
	int	tmp_c;
	int	tmp_i;

	if (s && s->next)
	{
		tmp_c = s->content;
		tmp_i = s->index;
		s->content = s->next->content;
		s->index = s->next->index;
		s->next->content = tmp_c;
		s->next->index = tmp_i;
	}
	if (c != 0)
		ft_lstadd_back(actions, ft_lstnew(c * SWAP, -1));
	return (1);
}

int	push(t_list **s1, t_list **s2, t_list **actions, int c)
{
	t_list	*tmp;

	if (s1)
	{
		tmp = (*s1)->next;
		if (s2)
			ft_lstadd_front(s2, ft_lstnew((*s1)->content, (*s1)->index));
		ft_lstdelone(*s1);
		*s1 = tmp;
	}
	if (c != 0)
		ft_lstadd_back(actions, ft_lstnew(c * PUSH, -1));
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
		ft_lstadd_back(actions, ft_lstnew(c * ROTATE, -1));
	return (1);
}

static t_list	*pop(t_list **s)
{
	t_list	*ret;
	t_list	*tmp;

	tmp = (*s);
	ret = NULL;
	while (tmp && tmp->next->next)
		tmp = tmp->next;
	ret = ft_lstnew(tmp->next->content, tmp->next->index);
	ft_lstdelone(tmp->next);
	tmp->next = NULL;
	return (ret);
}

int	rrotate(t_list **s, t_list **actions, int c)
{
	t_list	*tmp;

	tmp = pop(s);
	ft_lstadd_front(s, tmp);
	if (c != 0)
		ft_lstadd_back(actions, ft_lstnew(c * RROTATE, -1));
	return (1);
}
