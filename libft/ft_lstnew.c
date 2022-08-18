/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 20:42:25 by asoler            #+#    #+#             */
/*   Updated: 2022/08/18 15:44:00 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(long int content, long int index)
{
	t_list	*result;

	result = malloc(sizeof(t_list));
	if (!result)
		return (0);
	result->content = content;
	result->index = index;
	result->next = NULL;
	result->prev = NULL;
	return (result);
}
