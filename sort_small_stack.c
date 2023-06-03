/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:34:24 by kogitsu           #+#    #+#             */
/*   Updated: 2023/06/03 20:14:38 by kogitsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	judge_rotate_or_rrotate(t_stack *stack, int min, int max)
{
	int		count1;
	int		count2;
	t_node	*tmp_node;

	count1 = 0;
	tmp_node = stack->sentry->prev;
	while (tmp_node->next != stack->sentry)
	{
		if (tmp_node->index >= min && tmp_node->index <= max)
			break ;
		count1++;
		tmp_node = tmp_node->next;
	}
	tmp_node = stack->sentry->prev;
	count2 = 0;
	while (tmp_node->prev != stack->sentry)
	{
		if (tmp_node->index >= min && tmp_node->index <= max)
			break ;
		count2++;
		tmp_node = tmp_node->prev;
	}
	if (count1 < count2)
		return (1);
	else
		return (0);
}

void	sort_small_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_size(stack_a) == 1)
		return ;
	else if (stack_size(stack_a) == 2)
		sort_two_elem(stack_a);
	else if (stack_size(stack_a) == 3)
		sort_three_elem_a(stack_a);
	else if (stack_size(stack_a) >= 4 && stack_size(stack_a) <= 6)
		sort_over_four_elem(stack_a, stack_b);
	else
		return ;
}
