/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 18:52:53 by kogitsu           #+#    #+#             */
/*   Updated: 2023/05/29 15:18:37 by kogitsu          ###   ########.fr       */
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

void	do_ra(t_stack *stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}

void	do_rb(t_stack *stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}

void	do_rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}
