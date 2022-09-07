/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:11:47 by asoler            #+#    #+#             */
/*   Updated: 2022/09/07 20:50:06 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_smaller(t_list *a)
{
	t_list	*lst;

	lst = a;
	a = a->next;
	lst->index = 0;
	while (a)
	{
		if (a->content < lst->content)
			lst = a;
		lst->index++;
		a = a->next;
	}
	return (lst);
}

void	push_smallers(t_stack *a, t_stack *b)
{
	t_list	*smaller;

	smaller = find_smaller(a->lst);
	while (a->lst->content != smaller->content)
	{
		if (smaller->index < 2)
			reverse_rotate(a);
		else
			rotate(a);
	}
	push(a, b);
}

void	free_list(t_list *list)
{
	t_list	*aux;

	while (list)
	{
		aux = list;
		list = list->next;
		free(aux);
	}
}

int	is_sorted(t_list *list)
{
	while (list->next)
	{
		if (list->content != (list->next->content - 1))
			return (0);
		list = list->next;
	}
	return (1);
}
