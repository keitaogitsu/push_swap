/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 12:30:06 by kogitsu           #+#    #+#             */
/*   Updated: 2023/05/30 16:35:08 by kogitsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	int	tmp_value;
	int	tmp_index;

	if (stack_size(stack) == 0 || stack_size(stack) == 1)
		return ;
	else
	{
		tmp_value = stack->sentry->prev->value;
		stack->sentry->prev->value = stack->sentry->prev->prev->value;
		stack->sentry->prev->prev->value = tmp_value;
		tmp_index = stack->sentry->prev->index;
		stack->sentry->prev->index = stack->sentry->prev->prev->index;
		stack->sentry->prev->prev->index = tmp_index;
	}
}

void	do_sa(t_stack *stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
}

void	do_sb(t_stack *stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
}

void	do_ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}
