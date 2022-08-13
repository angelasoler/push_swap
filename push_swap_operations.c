/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 16:03:30 by asoler            #+#    #+#             */
/*   Updated: 2022/08/13 19:55:16 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	operate(t_list *lst, int *f(t_list *, t_list *))
// {
// 	if (!lst)
// 		return ;
// 	f(lst);
// 	return (1);
// }

// int	operate_both(t_list *a, t_list *b, int *f(t_list *))
// {
// 	f(a);
// 	f(b);
// }

int	swap(t_list **lst)
{
	t_list	*temp;
	t_list	*aux;

	if (!*lst)
		return (1);
	temp = *lst;
	aux = lst[0]->next;
	*lst = lst[0]->next->next;
	ft_lstadd_front(lst, temp);
	ft_lstadd_front(lst, aux);
	return (0);
}

int	push(t_list **lst, t_list **aux)
{
	t_list	*temp;

	if (!*lst)
		return (1);
	temp = lst[0]->next;
	ft_lstadd_front(aux, *lst);
	*lst = temp;
	return (0);
}

// int	rotate(t_list *lst)
// {
	
// }

// int	reverse_rotate(t_list *lst)
// {
// }

// sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
// sb (swap b): Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.
// ss : sa and sb at the same time.
// pa (push a): Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.
// pb (push b): Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.
// rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.
// rr : ra and rb at the same time.
// rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.
// rrb (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one.
// rrr : rra and rrb at the same time.