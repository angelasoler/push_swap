/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:11:47 by asoler            #+#    #+#             */
/*   Updated: 2022/08/19 16:56:15 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_list *list)
{
	while (list)
	{
		ft_printf("%d\n", list->content);
		list = list->next;
	}
}

void	print_list_in_reverse(t_list *list)
{
	t_list	*tail;

	tail = ft_lstlast(list);
	while (tail)
	{
		ft_printf("%d\n", tail->content);
		tail = tail->prev;
	}
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
