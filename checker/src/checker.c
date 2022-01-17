/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:10:57 by shocquen          #+#    #+#             */
/*   Updated: 2022/01/17 17:25:11 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	*ret;

	(void)argv;
	if (argc == 1)
	{
		ret = get_next_line(0);
		ft_printf("%s", ret);
		while (ret)
		{
			ft_printf("%s", ret);
			ret = get_next_line(0);
		}
	}
	ft_printf("\n");
	return (0);
}