/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 14:59:24 by asoler            #+#    #+#             */
/*   Updated: 2022/08/27 23:45:04 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_smaller(t_list *a)
{
	t_list	*lst;
	int		index;

	lst = a;
	a = a->next;
	index = 1;
	while (a)
	{
		if (a->content < lst->content)
			lst = a;
		index++;
		a = a->next;
	}
	return (lst);
}

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
	t_list	*smaller;

	b.lst = NULL;
	b.type = 'b';
	if (is_sorted(a->lst))
		return (b);
	if (a->size <= 5)
	{
		smaller = find_smaller(a->lst);
		while (ft_lstsize(a->lst) > 3)
		{
			while (a->lst->content != smaller->content)
				rotate(a);
			push(a, &b);
			smaller = find_smaller(a->lst);
		}
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
	a.type = 'a';
	a.size = argc - 1;
	a.lst = NULL;
	a.rrr = 0;
	a.dup = 0;
	a.arr = calloc((a.size + 2), sizeof(long int));
	a.arr[0] = 1;
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
