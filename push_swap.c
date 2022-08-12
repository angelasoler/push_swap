#include "push_swap.h"
void	free_list(t_list *list)
{
	t_list	*aux;

	while(list)
	{
		aux = list;
		list = list->next;
		free(aux);
	}
}

void	alloc_to_list(char *s, t_list *list)
{
	int		n;
	t_list	*new;

	n = ft_atoi(s);
	new = ft_lstnew(&n);
	ft_lstadd_back(&list, new);
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
	int	i;

	i = 1;
	while (argv[i])
	{
		if (verify_digits(argv[i]))
		{
			free_list(*a);
			*a = NULL;
			return (1);
		}
		alloc_to_list(argv[i], *a);
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_list *a;

	verify_arg_rules(argv, &a);
	if (!a)
	{
		ft_printf("Error\n");
		return(-1);
	}
	// sort(stack.a);
	return (argc);
}
