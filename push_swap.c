/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 14:59:24 by asoler            #+#    #+#             */
/*   Updated: 2022/08/13 22:11:28 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*sort(t_list **a)
{
	t_list	*b;

	b = NULL;
	if (!push(a, &b))
		ft_printf("pb\n");
	if (!push(a, &b))
		ft_printf("pb\n");
	if (!push(a, &b))
		ft_printf("pb\n");
	if (!push(a, &b))
		ft_printf("pb\n");
	if (!operate_both(a, &b, swap))
		ft_printf("ss\n");
	if (!operate_both(a, &b, rotate))
		ft_printf("rr\n");
	if (!operate_both(a, &b, reverse_rotate))
		ft_printf("rrr\n");
	return (b);
}

int	main(int argc, char *argv[])
{
	t_data	stack;

	stack.a = NULL;
	verify_arg_rules(argv, &stack.a);
	if (!stack.a)
	{
		ft_printf("Error\n");
		return (-1);
	}
	print_list(stack.a);
	stack.b = sort(&stack.a);
	ft_printf("   ---after sort ---\na: \n");
	print_list(stack.a);
	ft_printf("b:\n");
	print_list(stack.b);
	free_list(stack.a);
	free_list(stack.b);
	return (argc);
}
