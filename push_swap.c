/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 14:59:24 by asoler            #+#    #+#             */
/*   Updated: 2022/08/18 16:06:32 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *find_smaller_and_bigger(t_list *a, char type)
{
	t_list	*small;
	t_list	*big;
	int		index;

	big = a; 
	small = a; 
	a = a->next;
	index = 1;
	while (a)
	{
		if (a->content > big->content)
		{
			big =  a;
			big->index = index;
		}
		if (a->content < small->content)
		{
			small = a;
			small->index = index;
		}
		index++;
		a = a->next;
	}
	if (type == 'b')
		return (big);
	else
		return (small);
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
	if (last->content != bigger->content && a->size == 3)
	{
		if (a->lst->content == bigger->content)
		{
			rotate(a);
		}
		else
			reverse_rotate(a);
	}
	if (a->lst->content > a->lst->next->content)
		swap(a);
}

t_stack	sort(t_stack *a)
{
	t_stack	b;

	b.lst = NULL;
	b.type = 'b';
	if (a->size <= 3)
		sort_3(a);
	return (b);
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;

	a.type = 'a';
	a.lst = NULL;
	a.rrr = 0;
	verify_arg_rules(argv, &a);
	if (!a.lst)
	{
		ft_printf("Error\n");
		return (-1);
	}
	normalize(&a);
	b = sort(&a);
	b.rrr = 0;
	ft_printf("a:\n");
	print_list(a.lst);
	if (b.lst)
	{
		ft_printf("   ---after sort ---\n\n");
		ft_printf("b:\n");
		print_list(b.lst);
	}
	free_list(a.lst);
	free_list(b.lst);
	return (argc);
}
