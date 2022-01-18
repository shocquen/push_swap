/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:15:07 by shocquen          #+#    #+#             */
/*   Updated: 2022/01/18 18:17:27 by shocquen         ###   ########.fr       */
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

void	pactions(t_list *actions)
{
	ft_lstiter(actions, &which_action);
}