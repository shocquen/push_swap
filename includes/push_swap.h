/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 11:07:12 by shocquen          #+#    #+#             */
/*   Updated: 2022/01/10 22:22:24 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <libft.h>

/* —————————— simple ——————————*/
int	swap(t_list *s, int c); /* sa, sb */
int	push(t_list **s1, t_list **s2, int c); /* pa, pb */
int	rotate(t_list *s, int c); /* ra, rb */
int	rrotate(t_list **s, int c); /* rra, rrb */

/*—————————— double ——————————*/
// void	dbl_swap(t_list s1, t_list s2); /* ss */
// void	dbl_rotate(t_list s1, t_list s2); /* rr */
// void	dbl_rrotate(t_list s1, t_list s2); /* rrr */

/*—————————— Checks ——————————*/
int	check_dbl(t_list *s);
int	check_d(char *str);
int	is_sorted(t_list *s);

/*—————————— Sort ——————————*/
int	ps_sort(t_list **stack_a, int c);
int	ps_sort_3(t_list **s);
int	ps_sort_5(t_list **s);

/*—————————— Sort ——————————*/
int	get_lowest(t_list *s);
int	get_hiest(t_list *s);

#endif