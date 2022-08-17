/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 14:59:24 by asoler            #+#    #+#             */
/*   Updated: 2022/08/17 14:42:42 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *find_smaller_and_bigger(t_list *a, t_list **bigger)
{
	t_list *small;
	int		index;

	*bigger = a; 
	small = a; 
	// a = a->next;
	index = 1;
	while (a)
	{
		if (a->content > bigger[0]->content)
		{
			*bigger =  a;
			bigger[0]->index = index;
		}
		if (a->content < small->content)
		{
			small = a;
			small->index = index;
		}
		index++;
		a = a->next;
	}
	return (small);
}

t_stack	sort(t_stack *a, int list_size)
{
	t_stack	b;
	t_list	*smaller;
	t_list	*bigger;
	int		mean;

	b.type = 'b';
	b.lst = NULL;
	smaller = find_smaller_and_bigger(a->lst, &bigger);
	mean = list_size / 2;
	swap(a);
	// reverse_rotate(a);
	// // swap(a);
	// reverse_rotate(a);
	// // swap(a);
	// // ft_printf("a inside sort:\n");
	// // print_list(a->lst);
	// reverse_rotate(a);
	// swap(a);
	// push(a, &b);
	// push(a, &b);
	// push(a, &b);
	// push(a, &b);
	// while (list_size >= mean)
	// {
	// 	if (smaller->index <= (list_size / 2))
	// 	{
	// 		while (a->lst->content != smaller->content)
	// 		{
	// 			if (a->lst->content > a->lst->next->content)
	// 				swap(a);
	// 			reverse_rotate(a);
	// 		}
	// 		push(a, &b);
	// 	}
	// 	smaller = find_smaller_and_bigger(a->lst, &bigger);
	// 	list_size = ft_lstsize(a->lst);
	// 	if (list_size == 2)
	// 	{
	// 		if (a->lst->content > a->lst->next->content)
	// 			swap(a);
	// 	}
	// 	// else
	// 	// {
	// 	// 	while (a->lst->content != smaller->content)
	// 	// 	{
	// 	// 		rotate(a);
	// 	// 	}
	// 	// 	push(a, &b);
	// 	// 	if (a->lst->content > a->lst->next->content)
	// 	// 		swap(a);
	// 	// 	smaller = find_smaller_and_bigger(a->lst, &bigger);
	// 	// 	list_size = ft_lstsize(a->lst);
	// 	// }
	// }
	// sort_a(a);
	// ft_printf("big= %d[%d]\nsmall=%d[%d]\naverage = %d\n", bigger->content, bigger->index, smaller->content, smaller->index, mean);
	// ft_printf("size list = %d\n", list_size);
	return (b);
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;

	a.type = 'a';
	a.lst = NULL;
	verify_arg_rules(argv, &a.lst);
	if (!a.lst)
	{
		ft_printf("Error\n");
		return (-1);
	}
	a.size = ft_lstsize(a.lst);
	b = sort(&a, a.size);
	ft_printf("a:\n");
	print_list(a.lst);
	if (!b.lst)
		ft_printf("\n\n ˜˜˜˜˜˜˜˜˜˜b is empty\n");
	else
	{
		ft_printf("   ---after sort ---\n\n");
		ft_printf("b:\n");
		print_list(b.lst);
	}
	free_list(a.lst);
	free_list(b.lst);
	return (argc);
}
