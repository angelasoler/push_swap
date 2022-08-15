/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 16:03:30 by asoler            #+#    #+#             */
/*   Updated: 2022/08/15 16:14:08 by asoler           ###   ########.fr       */
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
	int		size;

	size = ft_lstsize(*lst);
	if (size < 2)
	{
		ft_printf("wtf arg -> cannot do that\n");
		return (1);
	}
	temp = *lst;
	aux = lst[0]->next;
	*lst = aux->next;
	ft_lstadd_front(lst, temp);
	ft_lstadd_front(lst, aux);
	return (0);
}

int	push(t_list **lst, t_list **aux)
{
	t_list	*temp;
	int		size;

	size = ft_lstsize(*lst);
	if (size < 1)
	{
		ft_printf("wtf arg -> cannot do that\n");
		return (1);
	}
	temp = lst[0]->next;
	ft_lstadd_front(aux, *lst);
	temp->prev = NULL;
	*lst = temp;
	return (0);
}

int	rotate(t_list **lst)
{
	t_list	*aux;
	int		size;

	size = ft_lstsize(*lst);
	if (size <= 1)
	{
		ft_printf("wtf arg -> cannot do that\n");
		return (1);
	}
	aux = *lst;
	*lst = lst[0]->next;
	lst[0]->prev = NULL;
	aux->next = NULL;
	ft_lstadd_back(lst, aux);
	return (0);
}

int	reverse_rotate(t_list **lst)
{
	t_list	*last;
	int		size;

	size = ft_lstsize(*lst);
	if (size <= 1)
	{
		ft_printf("wtf arg -> cannot do that\n");
		return (1);
	}
	last = ft_lstlast(*lst);
	last->prev->next = NULL;
	last->prev = NULL;
	ft_lstadd_front(lst, last);
	return (0);
}
