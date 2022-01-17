/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 12:36:46 by shocquen          #+#    #+#             */
/*   Updated: 2022/01/05 14:48:24 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
	Iterates the list ’lst’ and applies the function
	’f’ to the content of each element.
*/

void	ft_lstiter(t_list *lst, void (*f)(int))
{
	while (lst)
	{
		if (f)
			(f)(lst->content);
		lst = lst->next;
	}
}
