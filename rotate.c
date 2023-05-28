/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 18:52:53 by kogitsu           #+#    #+#             */
/*   Updated: 2023/05/28 19:39:57 by kogitsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stack)
{
	t_node	*tmp_node;

	tmp_node = stack->sentry->prev;
	stack->sentry->prev->prev->next = stack->sentry;
	stack->sentry->prev = stack->sentry->prev->prev;
	if (add_node_next_sentry(stack, tmp_node))
		return ;
}

void	double_rotate(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}

void	r_rotate(t_stack *stack)
{
	t_node	*tmp_node;

	tmp_node = stack->sentry->next;
	stack->sentry->next->next->prev = stack->sentry;
	stack->sentry->next = stack->sentry->next->next;
	if (add_node_prev_sentry(stack, tmp_node))
		return ;
}

void	double_r_rotate(t_stack *stack_a, t_stack *stack_b)
{
	r_rotate(stack_a);
	r_rotate(stack_b);
}
