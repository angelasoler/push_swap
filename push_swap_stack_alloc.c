/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_alloc.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:55:39 by asoler            #+#    #+#             */
/*   Updated: 2022/08/19 21:21:06 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	verify_digits(char *n)
{
	if (*n == '+' || *n == '-')
		n++;
	while (*n)
	{
		if (*n >= '0' && *n <= '9')
			n++;
		else
			return (1);
	}
	return (0);
}

void	sort_array(long int *arr)
{
	int			sorted;
	long int	aux;
	int			i;

	sorted = 0;
	i = 0;
	while (!sorted)
	{
		sorted = 1;
		while (arr[i + 1])
		{
			if (arr[i] > arr[i + 1])
			{
				aux = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = aux;
				sorted = 0;
			}
			i++;
		}
		i = 0;
	}
}

void	normalize(t_stack *a)
{
	t_list		*head;
	long int	i;

	i = 1;
	sort_array(&a->arr[1]);
	while (i <= a->size)
	{
		head = a->lst;
		while (head->content != a->arr[i])
			head = head->next;
		head->content = i - 1;
		i++;
	}
	free(a->arr);
}

int	verify_dup_num(t_list *lst, long int n)
{
	while (lst)
	{
		if (lst->content == n)
			return (1);
		lst = lst->next;
	}
	return (0);
}

int	verify_arg_rules(char **argv, t_stack *a)
{
	long int	i;
	long int	n;
	t_list		*new;

	n = 0;
	i = 1;
	while (argv[i])
	{
		n = ft_atoi(argv[i]);
		a->arr[i] = n;
		a->dup = verify_dup_num(a->lst, n);
		new = ft_lstnew(n, i);
		ft_lstadd_back(&a->lst, new);
		if (verify_digits(argv[i]) || a->dup \
		|| n < MIN_INT || n > MAX_INT)
		{
			free_list(a->lst);
			free(a->arr);
			a->lst = NULL;
			return (1);
		}
		i++;
	}
	return (0);
}
