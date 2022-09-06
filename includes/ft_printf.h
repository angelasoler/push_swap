/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 01:05:04 by asoler            #+#    #+#             */
/*   Updated: 2022/09/06 15:57:50 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# include <stdarg.h>
# include "libft.h"
# include <unistd.h>
# define FT_PRINTF_H

typedef struct s_vars
{
	char			*s;
	char			c;
	int				sn;
	unsigned int	un;
	unsigned long	address;
}	t_vars;

int	ft_printf(const char *s, ...);

int	ft_printf_int(int d);

int	ft_printf_address(unsigned long n);

int	ft_printf_char(char c);

int	ft_printf_str(char *s);

int	ft_printf_int_as_hex(unsigned int n, char c);

int	ft_printf_usig_int(unsigned int n);

#endif
