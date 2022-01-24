/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:15:07 by shocquen          #+#    #+#             */
/*   Updated: 2022/01/24 17:52:00 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* TESTS FUNCTIONS */

static void	pcontent(int c)
{
	ft_printf("> %d ", (char)c);
}

void	ptest(t_list *s, char *str)
{
	ft_printf("%s", str);
	ft_lstiter(s, &pcontent);
	ft_printf("\n");
}

/* Know which actions where dones */

static void pa_filter(t_list **actions, t_list **ret)
{
	int	i;
	int	j;

	i = 0;
	while((*actions) && (*actions)->content == (PUSH * -1))
	{
		i++;
		*actions = (*actions)->next;
	}
	j = 0;
	while((*actions) && (*actions)->content == PUSH)
	{
		j++;
		*actions = (*actions)->next;
	}
	(void)ret;
	i = i - j;
	if (i < 0)
	{
		i *= -1;
		j = PUSH;
	}
	else
		j = -PUSH;
	while (i--)
		ft_lstadd_back(ret, ft_lstnew(j, -1));
	
}
static t_list	*actions_filter(t_list *actions)
{
	t_list *ret;

	ret = NULL;
	while(actions)
	{ 
		if (actions->content == (PUSH * -1))
			pa_filter(&actions, &ret);
		else
		{
			ft_lstadd_back(&ret, ft_lstnew(actions->content, -1));
			actions = actions->next;
		}
		// pb_filter(actions, ret);
	}
	return (ret);
}

static void which_action(int a)
{
	char c;

	if (a > 0)
		c = 'a';
	else
	{
		c = 'b';
		a *= -1;
	}
	if (a == SWAP)
		ft_printf("s%c", c);
	else if (a == PUSH)
		ft_printf("p%c", c);
	else if (a == ROTATE)
		ft_printf("r%c", c);
	else if (a == RROTATE)
		ft_printf("rr%c", c);
	ft_printf("\n");
}

void	pactions(t_list **actions)
{
	*actions = actions_filter(*actions);
	ft_lstiter((*actions), &which_action);
}