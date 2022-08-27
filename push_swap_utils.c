/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:11:47 by asoler            #+#    #+#             */
/*   Updated: 2022/08/27 13:53:08 by asoler           ###   ########.fr       */
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

long	almost_sorted(t_list *list)
{
	long	result;

	result = -1;
	list = list->next;
	while (list->next)
	{
		if (list->content != (list->next->content - 1) && \
		list->content != (list->prev->content + 1))
		{
			result = list->content;
			break ;
		}
		list = list->next;
	}
	return (result);
}
