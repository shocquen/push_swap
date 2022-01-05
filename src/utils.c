#include "push_swap.h"

static void printcnt(int c)
{
	ft_printf("> %d ", (char)c);
}

void	swap(t_list *s)
{
	int	swp;

	if (s &&s->next)
	{
	swp = s->content;
	s->content = s->next->content;
	s->next->content = swp;
	}
}

void	push(t_list *s1, t_list *s2)
{
	t_list	*tmp;

	if (s1)
	{
		ft_printf("s2 ?: %s\n", s2? "YES" : "NO");
		if (s2)
			ft_lstadd_front(&s2, ft_lstnew(s1->content));
		else
			s2 = ft_lstnew(s1->content);
		tmp = s1->next;
		ft_lstdelone(s1);
		s1 = tmp;
		ft_lstiter(s2, &printcnt);
	}
}/* 

void	rotate(t_list *s)
{

}

void	rrotate(t_list *s)
{

} */