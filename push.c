/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 19:44:46 by kogitsu           #+#    #+#             */
/*   Updated: 2023/05/28 20:47:30 by kogitsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *receiving_stack, t_stack *pushing_stack)
{
	t_node	*tmp_node;

	if (pushing_stack->sentry->next == pushing_stack->sentry && \
		pushing_stack->sentry->prev == pushing_stack->sentry)
		return ;
	tmp_node = pushing_stack->sentry->prev;
	pushing_stack->sentry->prev->prev->next = pushing_stack->sentry;
	pushing_stack->sentry->prev = pushing_stack->sentry->prev->prev;
	if (add_node_prev_sentry(receiving_stack, tmp_node))
		return ;
}
