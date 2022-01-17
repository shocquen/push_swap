/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 10:29:58 by shocquen          #+#    #+#             */
/*   Updated: 2022/01/17 18:28:09 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

 

/* Return the index of lightest nb in a chunk*/

static int	get_lightest(t_list *lst, int min, int max)
{
	int	i;
	int	ret;
	int	size;
	int	weight;

	i = 0;
	ret = 0;
	size = ft_lstsize(lst);
	while (lst && !lst->next)
	{
		if (lst->content >= min && lst->content < max)
		{
			if (i > size / 2)
				weight = size - i;
			else
				weight = i;
			if (ret > weight)
				ret = weight;
		}
		lst = lst->next;
		i++;
	}
	return (weight);
}

int	ps_sort_100(t_list **a, t_list **b)
{
	(void)a;
	(void)b;
	return(0);
}

/* 

	int nb[1]
\	*(long *)nb = 0;
	int median = list_size / 2

	chunk_0 = => 0 && < 20
	chunk_1 = => 20 && < 40
	chunk_2 = => 40 && < 60
	chunk_3 = => 60 && < 80
	chunk_4 = => 80 && < 100

	nb[0]
*/

// ToDo
/* 

*/