/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 16:03:30 by asoler            #+#    #+#             */
/*   Updated: 2022/08/30 18:04:03 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_stack *stack)
{
	t_list	*temp;
	t_list	*aux;
	int		size;

	size = ft_lstsize(stack->lst);
	if (size < 2)
		return (1);
	temp = stack->lst;
	aux = stack->lst->next;
	stack->lst = aux->next;
	ft_lstadd_front(&stack->lst, temp);
	ft_lstadd_front(&stack->lst, aux);
	ft_printf("s%c\n", stack->type);
	return (0);
}

int	push(t_stack *from, t_stack *to)
{
	t_list	*head;
	int		size;

	head = from->lst;
	size = ft_lstsize(from->lst);
	if (size < 1)
		return (1);
	if (size != 1)
	{
		from->lst = from->lst->next;
		from->lst->prev = NULL;
	}
	ft_lstadd_front(&to->lst, head);
	if (size == 1)
		from->lst = NULL;
	ft_printf("p%c\n", to->type);
	return (0);
}

int	rotate(t_stack *stack)
{
	t_list	*aux;
	t_list	*aux1;
	int		size;

	size = ft_lstsize(stack->lst);
	if (size < 3)
		return (1);
	aux = stack->lst;
	aux1 = ft_lstnew(stack->lst->content);
	stack->lst = stack->lst->next;
	stack->lst->prev = NULL;
	aux->next = NULL;
	free(aux);
	ft_lstadd_back(&stack->lst, aux1);
	ft_printf("r%c\n", stack->type);
	return (0);
}

int	reverse_rotate(t_stack *stack)
{
	t_list	*last;
	int		size;

	size = ft_lstsize(stack->lst);
	if (size < 3)
		return (1);
	last = ft_lstlast(stack->lst);
	last->prev->next = NULL;
	last->prev = NULL;
	ft_lstadd_front(&stack->lst, last);
	ft_printf("rr%c\n", stack->type);
	return (0);
}
