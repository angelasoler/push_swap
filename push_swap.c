/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 14:59:24 by asoler            #+#    #+#             */
/*   Updated: 2022/08/27 14:24:32 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_smaller_and_bigger(t_list *a, char type)
{
	t_list	*lst;
	int		index;

	lst = a;
	a = a->next;
	index = 1;
	while (a)
	{
		if (a->content > lst->content && type == 'b')
			lst = a;
		if (a->content < lst->content && type == 's')
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

long	find_n(t_list *list, long n)
{
	while (list)
	{
		if (list->content == n)
			return (n);
		list = list->next;
	}
	return (-1);
}

// void	sort_n(t_stack *a, t_stack *b)
// {
// }

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
		smaller = find_smaller_and_bigger(a->lst, 's');
		while (ft_lstsize(a->lst) > 3)
		{
			while (a->lst->content != smaller->content)
				rotate(a);
			push(a, &b);
			smaller = find_smaller_and_bigger(a->lst, 's');
		}
		sort_3(a);
		while (b.lst)
			push(&b, a);
	}
	// else
	// 	sort_n(a, &b);
	return (b);
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;

	a.type = 'a';
	a.size = argc - 1;
	a.lst = NULL;
	a.rrr = 0;
	b.rrr = 0;
	a.dup = 0;
	a.arr = calloc((a.size + 2), sizeof(long int));
	a.arr[0] = 1;
	verify_arg_rules(argv, &a);
	if (!a.lst)
	{
		ft_printf("Error\n");
		return (-1);
	}
	normalize(&a);
	// ft_printf("-- --before sort a:\n");
	// print_list(a.lst);
	b = sort(&a);
	// ft_printf("---- sorted a:\n");
	// print_list(a.lst);
	// ft_printf(" --- a print reverse:\n");
	// print_list_in_reverse(a.lst);
	// if (b.lst)
	// {
	// 	ft_printf("   ---after sort ---\n\n");
	// 	ft_printf("b:\n");
	// 	print_list(b.lst);
	// 	// ft_printf("b print reverse:\n");
	// 	// print_list_in_reverse(b.lst);
	// }
	free_list(a.lst);
	free_list(b.lst);
	return (argc);
}
