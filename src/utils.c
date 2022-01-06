#include "push_swap.h"

/* static void printcnt(int c)
{
	ft_printf("> %d ", (char)c);
} */

void	swap(t_list *s)
{
	int	tmp;

	if (s && s->next)
	{
		tmp = s->content;
		s->content = s->next->content;
		s->next->content = tmp;
	}
}

void	push(t_list **s1, t_list **s2)
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
} 

void	rotate(t_list *s)
{
	while(s)
	{
		swap(s);
		s = s->next;
	}
}

static int	pop(t_list **s)
{
	int	ret;
	t_list	*tmp;

	tmp = (*s);
	while (tmp && tmp->next->next)
		tmp = tmp->next;
	ret = tmp->next->content;
	ft_lstdelone(tmp->next);
	tmp->next = NULL;
	return (ret);
}

void	rrotate(t_list **s)
{
	int	tmp;

	tmp = pop(s);
	ft_lstadd_front(s, ft_lstnew(tmp));
}
