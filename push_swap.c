/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 14:59:24 by asoler            #+#    #+#             */
/*   Updated: 2022/08/25 16:35:01 by asoler           ###   ########.fr       */
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
	t_list	*bigger;
	t_list	*last;
	int		mean;

	if (a->size == 1)
		return ;
	last = ft_lstlast(a->lst);
	bigger = find_smaller_and_bigger(a->lst, 'b');
	mean = a->size / 2;
	if (last->content != bigger->content && ft_lstsize(a->lst) == 3)
	{
		if (a->lst->content != bigger->content)
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

void	sort_n(t_stack *a, t_stack *b)
{
	long	middle;
	t_list	*smaller;
	long	not_sorted;
	long	i;

	middle = a->size / 2;
	smaller = find_smaller_and_bigger(a->lst, 's');
	// b->lst = ft_lstnew(257);
	i = 0;
	// ------- shitty algorith until 7 * some cases ----
	// while (!is_sorted(a->lst))
	// {
	// 	if (i < (a->size * 2))
	// 	{
	// 		if (a->lst->content > a->lst->next->content)
	// 			swap(a);
	// 		else
	// 			reverse_rotate(a);
	// 		i++;
	// 	}
	// 	not_sorted = almost_sorted(a->lst);
	// 	if (not_sorted < 0)
	// 	{
	// 		while (!is_sorted(a->lst) && !b->lst)
	// 		{
	// 			ft_printf("not sorted = %d\n", not_sorted);
	// 			print_list(a->lst);
	// 			rotate(a);
	// 		}
	// 			// rotate(a);
	// 		break;
	// 	}
	// 	while (a->lst->content != not_sorted)
	// 	{
	// 		ft_printf("not sorted = %d\n", not_sorted);
	// 		rotate(a);
	// 	}
	// 	push(a, b);
	// 	if (find_n(a->lst, not_sorted + 1) >= 0)
	// 	{
	// 		while (a->lst->content != (not_sorted + 1))
	// 		{
	// 			ft_printf("not sorted = %d\n", not_sorted);
	// 			rotate(a);
	// 		}
	// 	}
	// 	else
	// 	{
	// 		while (a->lst->content != smaller->content)
	// 		{
	// 			ft_printf("not sorted = %d\n", not_sorted);
	// 			rotate(a);
	// 		}
	// 			// rotate(a);
	// 	}
	// 	push(b, a);
	// 	// break;
	// }
	// ----- divide minor middle of list into b stack ----
	// while (ft_lstsize(a->lst) > 3)
	// {
	// 	if (a->lst->content >= middle && a->size <= 6)
	// 		rotate(a);
	// 	else if (a->lst->content > middle && a->size > 6)
	// 		rotate(a);
	// 	else
	// 		push(a, b);
	// }
	// if (ft_lstsize(a->lst) <= 3)
	// 	sort_3(a);
	// else
	// {
	// 	while (!is_sorted(a->lst))
	// 	{
	// 		if (a->lst->content > a->lst->next->content)
	// 			swap(a);
	// 		else
	// 			reverse_rotate(a);
	// 	}
	// }
	// while (ft_lstsize(b->lst))
	// {
	// 	if (b->lst->content != (a->lst->content - 1))
	// 	{
	// 		if (ft_lstsize(b->lst) < 3)
	// 			swap(b);
	// 		else
	// 			rotate(b);
	// 	}
	// 	else
	// 	{
	// 		push(b, a);
	// 	}
	// }
}

t_stack	sort(t_stack *a)
{
	t_stack	b;

	b.lst = NULL;
	b.type = 'b';
	if (is_sorted(a->lst))
		return (b);
	if (a->size <= 3)
		sort_3(a);
	else
		sort_n(a, &b);
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
	ft_printf("before sort a:\n");
	print_list(a.lst);
	b = sort(&a);
	ft_printf("a:\n");
	print_list(a.lst);
	ft_printf("a print reverse:\n");
	print_list_in_reverse(a.lst);
	if (b.lst)
	{
		ft_printf("   ---after sort ---\n\n");
		ft_printf("b:\n");
		print_list(b.lst);
		// ft_printf("b print reverse:\n");
		// print_list_in_reverse(b.lst);
	}
	free_list(a.lst);
	free_list(b.lst);
	return (argc);
}
