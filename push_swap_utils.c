/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:11:47 by asoler            #+#    #+#             */
/*   Updated: 2022/08/16 18:13:41 by asoler           ###   ########.fr       */
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

int	verify_arg_rules(char **argv, t_list **a)
{
	int		i;
	int		n;
	t_list	*new;

	i = 1;
	while (argv[i])
	{
		if (verify_digits(argv[i]))
		{
			free_list(*a);
			*a = NULL;
			return (1);
		}
		n = ft_atoi(argv[i]);
		new = ft_lstnew(n, i);
		ft_lstadd_back(a, new);
		i++;
	}
	return (0);
}
