/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 16:03:30 by asoler            #+#    #+#             */
/*   Updated: 2022/08/13 22:12:38 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	operate_both(t_list **a, t_list **b, int f(t_list **))
{
	f(a);
	f(b);
	return (0);
}

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

int	rotate(t_list **lst)
{
	t_list	*aux;

	if (!*lst)
		return (1);
	aux = *lst;
	*lst = lst[0]->next;
	aux->next = NULL;
	ft_lstadd_back(lst, aux);
	return (0);
}

int	reverse_rotate(t_list **lst)
{
	int		size;

	if (!*lst)
		return (1);
	size = ft_lstsize(*lst) - 1;
	while (size > 0)
	{
		rotate(lst);
		size--;
	}
	return (0);
}
