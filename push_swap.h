/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:02:19 by asoler            #+#    #+#             */
/*   Updated: 2022/08/15 15:38:06 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# include "includes/libft.h"
# define PUSH_SWAP_H
# define MAX_INT 2147483647
# define MIT_INT -2147483648

typedef struct s_data
{
	t_list	*a;
	t_list	*b;
	t_list	*head;
	t_list	*tail;
}	t_data;

void	print_list(t_list *list);
void	free_list(t_list *list);
void	alloc_to_list(char *s, t_list **list);
int		verify_digits(char *n);
int		verify_arg_rules(char **argv, t_list **a);

int		push(t_list **lst, t_list **aux);
int		swap(t_list **lst);
int		operate_both(t_list **a, t_list **b, int f(t_list **));
int		rotate(t_list **lst);
int		reverse_rotate(t_list **lst);

#endif
