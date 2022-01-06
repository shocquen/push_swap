/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 11:07:12 by shocquen          #+#    #+#             */
/*   Updated: 2022/01/06 12:29:13 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <libft.h>

/* —————————— simple ——————————*/
void	swap(t_list *s); /* sa, sb */
void	push(t_list **s1, t_list **s2); /* pa, pb */
void	rotate(t_list *s); /* ra, rb */
void	rrotate(t_list **s); /* rra, rrb */

/*—————————— double ——————————*/
// void	dbl_swap(t_list s1, t_list s2); /* ss */
// void	dbl_rotate(t_list s1, t_list s2); /* rr */
// void	dbl_rrotate(t_list s1, t_list s2); /* rrr */

#endif