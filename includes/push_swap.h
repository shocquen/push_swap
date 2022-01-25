/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shocquen <shocquen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 11:07:12 by shocquen          #+#    #+#             */
/*   Updated: 2022/01/25 10:14:35 by shocquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <libft.h>

# define SWAP 1
# define ROTATE 2
# define RROTATE 3
# define PUSH 4

/* —————————— Actions ——————————*/
int	swap(t_list *s, t_list **actions, int c); /* sa, sb */
int	push(t_list **s1, t_list **s2, t_list **actions, int c); /* pa, pb */
int	rotate(t_list *s, t_list **actions, int c); /* ra, rb */
int	rrotate(t_list **s, t_list **actions, int c); /* rra, rrb */

/*—————————— Prints ——————————*/
void	ptest(t_list *s, char *str);
void	pactions(t_list **actions);
void	show_error(t_list **l, int free);

/*—————————— Checks ——————————*/
int	check_dbl(t_list *s);
int	check_d(char *str);
int	is_sorted(t_list *s);

/*—————————— Sorts ——————————*/
int	ps_sort(t_list **s, t_list **actions, int c);
int	ps_sort_3(t_list **s, t_list **actions);
int	ps_sort_4(t_list **a, t_list **b, t_list **actions);
int	ps_sort_5(t_list **a, t_list **b, t_list **actions);
int	ps_sort_100(t_list **a, t_list **b, t_list **actions);

/*—————————— Gets ——————————*/
int	get_lowest(t_list *s);
int	get_hiest(t_list *s);
int	get_value(t_list *s, int i);
int	get_index(t_list *lst, t_list *node);

#endif