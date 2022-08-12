/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_other_convs.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 00:35:24 by asoler            #+#    #+#             */
/*   Updated: 2022/07/06 14:28:44 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf_char(char c)
{
	write(1, &c, 1);
	return (0);
}

int	ft_printf_str(char *s)
{
	if (s)
	{
		write(1, s, ft_strlen(s));
		return (ft_strlen(s) - 1);
	}
	else
	{
		write(1, "(null)", 6);
		return (5);
	}
	return (0);
}
