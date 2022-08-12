/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 21:51:41 by asoler            #+#    #+#             */
/*   Updated: 2022/04/23 23:45:22 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*aux;
	t_list	*result;

	result = NULL;
	while (lst)
	{
		aux = ft_lstnew(f(lst->content));
		if (!aux->content)
		{
			ft_lstclear(&result, del);
			return (0);
		}
		ft_lstadd_back(&result, aux);
		lst = lst->next;
	}
	return (result);
}
