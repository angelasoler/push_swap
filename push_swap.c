/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 14:59:24 by asoler            #+#    #+#             */
/*   Updated: 2022/08/13 17:44:24 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*sort(t_list **a)
{
	t_list	*b;

	b = NULL;
	if (push(a, &b))
		ft_printf("pb");
	return (b);
}

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	verify_arg_rules(argv, &a);
	if (!a)
	{
		ft_printf("Error\n");
		return (-1);
	}
	print_list(a);
	b = sort(&a);
	ft_printf("   ---after sort ---\na: \n");
	print_list(a);
	ft_printf("b:\n");
	print_list(b);
	free_list(a);
	free_list(b);
	return (argc);
}
