/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:02:19 by asoler            #+#    #+#             */
/*   Updated: 2022/08/18 16:19:47 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# include "includes/libft.h"
# define PUSH_SWAP_H
# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct s_stack
{
	t_list	*lst;
	char	type;
	long int		size;
	long int		*arr;
	long int		*sort_list;
	long int		rrr;
}	t_stack;

typedef struct s_data
{
	t_list	*head;
	t_list	*tail;
}	t_data;

void	print_list(t_list *list);
void	free_list(t_list *list);
void	alloc_to_list(char *s, t_list **list);
int		verify_digits(char *n);
int		verify_arg_rules(char **argv, t_stack *a);
void	normalize(t_stack *a);

int		push(t_stack *from, t_stack *to);
int		swap(t_stack *stack);
int		operate_both(t_list **a, t_list **b, int f(t_list **));
int		rotate(t_stack *stack);
int		reverse_rotate(t_stack *stack);

#endif
