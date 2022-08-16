/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 16:03:30 by asoler            #+#    #+#             */
/*   Updated: 2022/08/16 20:09:29 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	operate_both(t_list **a, t_list **b, int f(t_list **))
{
	f(a);
	f(b);
	return (0);
}

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
	return (0);
}

int	push(t_stack *from, t_stack *to)
{
	t_list	*temp;
	int		size;

	size = ft_lstsize(from->lst);
	if (size < 1)
		return (1);
	else if (size == 1)
	{
		temp = from->lst->next;
		ft_lstadd_front(&to->lst, from->lst);
		// temp->prev = NULL;
		from->lst = temp;
		ft_printf("p%c\n", to->type);
	}
	else
	{
		temp = from->lst->next;
		ft_lstadd_front(&to->lst, from->lst);
		temp->prev = NULL;
		from->lst = temp;
		ft_printf("p%c\n", to->type);
	}
	return (0);
}

int	rotate(t_stack *stack)
{
	t_list	*aux;
	int		size;

	size = ft_lstsize(stack->lst);
	if (size <= 1)
		return (1);
	aux = stack->lst;
	stack->lst = stack->lst->next;
	stack->lst->prev = NULL;
	aux->next = NULL;
	ft_lstadd_back(&stack->lst, aux);
	ft_printf("r%c\n", stack->type);
	return (0);
}

int	reverse_rotate(t_stack *stack)
{
	t_list	*last;
	int		size;

	size = ft_lstsize(stack->lst);
	if (size <= 1)
		return (1);
	last = ft_lstlast(stack->lst);
	last->prev->next = NULL;
	last->prev = NULL;
	ft_lstadd_front(&stack->lst, last);
	ft_printf("rr%c\n", stack->type);
	return (0);
}
