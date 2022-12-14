/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:02:19 by asoler            #+#    #+#             */
/*   Updated: 2022/09/06 17:54:50 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# include "includes/libft.h"
# define PUSH_SWAP_H
# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct s_stack
{
	t_list		*lst;
	char		type;
	long int	size;
	long int	*arr;
	int			dup;
}	t_stack;

void	init_struct(t_stack *stack, int argc);
void	free_list(t_list *list);
void	alloc_to_list(char *s, t_list **list);
int		verify_digits(char *n);
int		verify_arg_rules(char **argv, t_stack *a);
void	normalize(t_stack *a);
int		is_sorted(t_list *list);
void	push_smallers(t_stack *a, t_stack *b);
t_list	*find_smaller(t_list *a);

int		push(t_stack *from, t_stack *to);
int		swap(t_stack *stack);
int		rotate(t_stack *stack);
int		reverse_rotate(t_stack *stack);

#endif
