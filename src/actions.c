/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:15:08 by shocquen          #+#    #+#             */
/*   Updated: 2022/01/10 15:32:45 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *s, int c)
{
	int	tmp;

	if (s && s->next)
	{
		tmp = s->content;
		s->content = s->next->content;
		s->next->content = tmp;
	}
	if (c != 0)
	{
		ft_printf("s%c\n", (char)c);
	}
}

void	push(t_list **s1, t_list **s2, int c)
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
	{
		ft_printf("p%c\n", (char)c);
	}
}

void	rotate(t_list *s, int c)
{
	while (s)
	{
		swap(s, 0);
		s = s->next;
	}
	if (c != 0)
	{
		ft_printf("r%c\n", (char)c);
	}
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

void	rrotate(t_list **s, int c)
{
	int	tmp;

	tmp = pop(s);
	ft_lstadd_front(s, ft_lstnew(tmp));
	if (c != 0)
	{
		ft_printf("rr%c\n", (char)c);
	}
}
