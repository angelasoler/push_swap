/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 22:49:16 by asoler            #+#    #+#             */
/*   Updated: 2022/08/19 16:20:28 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!*lst)
	{
		*lst = new;
		(*lst)->next = NULL;
		return ;
	}
	new->next = (*lst);
	new->prev = NULL;
	(*lst)->prev = new;
	*lst = new;
}
