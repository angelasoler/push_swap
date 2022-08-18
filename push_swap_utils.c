/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:11:47 by asoler            #+#    #+#             */
/*   Updated: 2022/08/18 17:35:58 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_list *list)
{
	t_list	*aux;

	while (list)
	{
		aux = list;
		list = list->next;
		ft_printf("%d\n", aux->content);
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
	t_list		*aux;
	long int	i;
	long int	count;

	count = 0;
	aux = a->lst;
	sort_array(&a->arr[1]);
	i = 0;
	while (a->arr[i])
	{
		ft_printf("n = %d\n", a->arr[i]);
		i++;
	}
	i = 1;
	while (count <= a->size)
	{
		ft_printf("loo\n\n = %d\n", a->arr[i]);
		ft_printf("lista\n\n = %d\n", aux->content);
		ft_printf("loo\n\n = %p\n", a->arr[i]);
		ft_printf("lista\n\n = %p\n", aux->content);
		while (aux->content != a->arr[i])
		{
			aux = aux->next;
			i++;
		}
		aux->content = i - 1;
		i = 1;
		count++;
		aux = a->lst;
	}
}

int	verify_arg_rules(char **argv, t_stack *a)
{
	long int		i;
	long int		n;
	t_list	*new;

	i = 1;
	n = 0;
	while (argv[i])
		i++;
	a->size = i - 1;
	i = 1;
	a->arr = calloc((a->size + 2), sizeof(long int));
	a->arr[0] = 1;
	while (argv[i])
	{
		if (verify_digits(argv[i]) || n < MIN_INT || n > MAX_INT)
		{
			free_list(a->lst);
			a->lst = NULL;
			return (1);
		}
		n = ft_atoi(argv[i]);
		a->arr[i] = n;
		new = ft_lstnew(n, i);
		ft_lstadd_back(&a->lst, new);
		i++;
	}
	return (0);
}
