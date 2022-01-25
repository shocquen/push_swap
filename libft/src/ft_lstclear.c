/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 12:34:06 by shocquen          #+#    #+#             */
/*   Updated: 2022/01/25 10:44:15 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Deletes and frees the given element and every
	successor of that element, using the function ’del’
	and free(3).
	Finally, the pointer to the list must be set to
	NULL.
*/

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;

	tmp = NULL;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}
