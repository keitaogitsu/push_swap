/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 07:37:33 by kogitsu           #+#    #+#             */
/*   Updated: 2023/05/27 23:43:42 by kogitsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct	s_node
{
	int				value;
	// int				index;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef	struct	s_stack
{
	t_node	*sentry;
}	t_stack;

#endif