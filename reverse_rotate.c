/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:12:21 by kogitsu           #+#    #+#             */
/*   Updated: 2023/06/10 11:16:27 by kogitsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_rotate(t_stack *stack)
{
	t_node	*tmp_node;

	tmp_node = stack->sentry->next;
	stack->sentry->next->next->prev = stack->sentry;
	stack->sentry->next = stack->sentry->next->next;
	if (add_node_prev_sentry(stack, tmp_node))
		return ;
}

void	do_rra(t_stack *stack_a)
{
	r_rotate(stack_a);
	ft_printf("rra\n");
}

void	do_rrb(t_stack *stack_b)
{
	r_rotate(stack_b);
	ft_printf("rrb\n");
}

void	do_rrr(t_stack *stack_a, t_stack *stack_b)
{
	r_rotate(stack_a);
	r_rotate(stack_b);
	ft_printf("rrr\n");
}
