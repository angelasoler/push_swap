/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 14:59:24 by asoler            #+#    #+#             */
/*   Updated: 2022/09/06 17:54:06 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack *a)
{
	t_list	*last;
	long	bigger;

	if (a->size == 1)
		return ;
	bigger = a->size - 1;
	last = ft_lstlast(a->lst);
	if (last->content != bigger)
	{
		if (a->lst->content != bigger)
			reverse_rotate(a);
		else
			rotate(a);
	}
	if (a->lst->content > a->lst->next->content)
		swap(a);
}

void	sort_n(t_stack *a, t_stack *b)
{
	long	shift;
	long	count;

	shift = 0;
	while (!is_sorted(a->lst))
	{
		count = 0;
		while (count < a->size)
		{
			if ((a->lst->content >> shift) & 1)
				rotate(a);
			else
				push(a, b);
			count++;
		}
		while (b->lst)
			push(b, a);
		shift++;
	}
}

t_stack	sort(t_stack *a)
{
	t_stack	b;

	b.lst = NULL;
	b.type = 'b';
	if (is_sorted(a->lst))
		return (b);
	if (a->size <= 5)
	{
		while (ft_lstsize(a->lst) > 3)
			push_smallers(a, &b);
		sort_3(a);
		while (b.lst)
			push(&b, a);
	}
	else
		sort_n(a, &b);
	return (b);
}

int	main(int argc, char *argv[])
{
	t_stack	a;

	if (argc == 1)
		exit (EXIT_FAILURE);
	init_struct(&a, argc);
	verify_arg_rules(argv, &a);
	if (!a.lst)
	{
		write(2, "Error\n", 6);
		exit (EXIT_FAILURE);
	}
	normalize(&a);
	sort(&a);
	free_list(a.lst);
	exit (EXIT_SUCCESS);
}
