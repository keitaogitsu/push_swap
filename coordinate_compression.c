/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate_compression.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:38:27 by kogitsu           #+#    #+#             */
/*   Updated: 2023/05/30 15:36:33 by kogitsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	c_compression(t_stack *stack)
{
	t_node *current_1;
	t_node *current_2;
	t_node *min;
	int		i;

	i = 0;
	current_1= stack->sentry->next;
	while (i < stack_size(stack))
	{
		min = current_1;
		current_2 = current_1;
		while (current_2 != stack->sentry)
		{
			if ((current_2->value < min->value) && !(current_2->cc_flag))
				min = current_2;
			current_2 = current_2->next;
		}
		if (!(min->cc_flag))
			min->index = i++;
		min->cc_flag = 1;
		if (current_1->cc_flag)
			current_1 = current_1->next;
	}
}
