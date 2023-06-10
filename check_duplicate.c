/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 11:39:28 by kogitsu           #+#    #+#             */
/*   Updated: 2023/06/10 11:51:55 by kogitsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicate(t_stack *stack)
{
	t_node	*node1;
	t_node	*node2;

	node1 = stack->sentry->next;
	while (node1 != stack->sentry)
	{
		node2 = node1->next;
		while (node2 != stack->sentry)
		{
			if (node1->value == node2->value)
				return (1);
			node2 = node2->next;
		}
		node1 = node1->next;
	}
	return (0);
}
