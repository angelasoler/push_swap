/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int_convs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 02:22:14 by asoler            #+#    #+#             */
/*   Updated: 2022/07/06 14:28:53 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	reverse_write_digits(char *s, int count)
{
	while (count)
	{
		count--;
		write(1, &s[count], 1);
	}
}

int	ft_printf_int(int d)
{
	char	*n;
	int		n_len;

	n = ft_itoa(d);
	n_len = ft_strlen(n);
	write(1, n, n_len);
	free(n);
	return (n_len - 1);
}

int	ft_printf_address(unsigned long n)
{
	char	temp[20];
	int		i;

	if (!n)
	{
		write(1, "(nil)", 5);
		return (4);
	}
	i = 0;
	while (n)
	{
		if (n % 16 > 9)
			temp[i] = (n % 16) + 87;
		else
			temp[i] = (n % 16) + 48;
		n /= 16;
		i++;
	}
	temp[i] = '\0';
	reverse_write_digits(temp, i);
	return (ft_strlen(temp) + 1);
}

int	ft_printf_usig_int(unsigned int n)
{
	int		i;
	int		r;
	char	digits[10];

	i = 0;
	while (n > 9)
	{
		digits[i] = (n % 10) + 48;
		n /= 10;
		i++;
	}
	digits[i] = n + 48;
	r = i;
	while (i >= 0)
	{
		write(1, &digits[i], 1);
		i--;
	}
	return (r);
}

int	ft_printf_int_as_hex(unsigned int n, char c)
{
	char	temp[9];
	int		i;

	if (!n)
	{
		write(1, "0", 1);
		return (0);
	}
	i = 0;
	while (n)
	{
		if (n % 16 > 9)
			temp[i] = (n % 16) + 87;
		else
			temp[i] = (n % 16) + 48;
		n /= 16;
		if (c == 'X')
			temp[i] = ft_toupper(temp[i]);
		i++;
	}
	temp[i] = '\0';
	reverse_write_digits(temp, i);
	return (ft_strlen(temp) - 1);
}
