/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 17:12:44 by shocquen          #+#    #+#             */
/*   Updated: 2021/11/26 11:11:16 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
	Returns a pointer to the last occurrence
	of the character c in the string s.
*/

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	if (!*s)
		return (NULL);
	len = ft_strlen(s);
	if (s[len] == (char)c)
		return ((char *)(s + len));
	len--;
	while (len--)
	{
		if (s[len] == (char)c)
			return ((char *)(s + len));
	}
	return (NULL);
}
