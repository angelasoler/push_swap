/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 22:10:08 by asoler            #+#    #+#             */
/*   Updated: 2022/05/24 14:26:16 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_count_digits(long int n, int *signal)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		*signal = 1;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	if (*signal)
		i++;
	return (i);
}

static char	*ft_char_to_int(char *dest, long int n, int size)
{
	if (n < 0)
		n *= -1;
	dest[size] = '\0';
	while (size > 0)
	{
		size--;
		dest[size] = (n % 10) + 48;
		n /= 10;
	}
	return (dest);
}

char	*ft_itoa(int n)
{
	long int	n1;
	int			size;
	int			signal;
	char		*result;

	if (n == 0)
	{
		result = malloc(sizeof(char) * 2);
		result[0] = '0';
		result[1] = '\0';
		return (result);
	}
	signal = 0;
	n1 = n;
	size = ft_count_digits(n, &signal);
	result = malloc(sizeof(char) * (size + 1));
	if (!result)
		return (0);
	ft_char_to_int(result, n1, size);
	if (signal)
		result[0] = '-';
	return (result);
}
