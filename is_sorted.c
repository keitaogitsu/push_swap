/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:43:15 by kogitsu           #+#    #+#             */
/*   Updated: 2023/06/10 16:56:48 by kogitsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	int		i;
	t_node	*top;

	i = 0;
	top = stack->sentry->prev;
	while (top != stack->sentry)
	{
		if (top->index == i)
		{
			top = top->prev;
			i++;
		}	
		else
			return (0);
	}
	return (1);
}
