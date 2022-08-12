/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 18:28:50 by asoler            #+#    #+#             */
/*   Updated: 2022/04/23 01:05:49 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*aux;
	t_list	*aux1;

	aux = *lst;
	aux1 = *lst;
	while (aux1)
	{
		del(aux->content);
		aux1 = aux->next;
		free(aux);
		aux = aux1;
	}
	*lst = 0;
}
