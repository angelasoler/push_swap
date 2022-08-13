/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoler <asoler@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:02:19 by asoler            #+#    #+#             */
/*   Updated: 2022/08/13 15:02:21 by asoler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# include "includes/libft.h"
# define PUSH_SWAP_H
# define MAX_INT 2147483647
# define MIT_INT -2147483648

typedef struct s_stack
{
	int		n;
	struct s_stack *next;
}	t_stack;

typedef struct s_data
{
	t_stack	*a;
	t_stack	*b;
}	t_data;

#endif
