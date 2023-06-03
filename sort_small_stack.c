/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:34:24 by kogitsu           #+#    #+#             */
/*   Updated: 2023/06/03 15:36:24 by kogitsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two_elem(t_stack *stack)
{
	if (stack->sentry->next->index < stack->sentry->prev->index)
		do_sa(stack);
}

void	sort_three_elem(t_stack *stack_a)
{
	t_node	*top;
	t_node	*bottom;
	
	top = stack_a->sentry->prev;
	bottom = stack_a->sentry->next;
	if ((bottom->index > top->index) && (top->index > top->prev->index))
		do_sa(stack_a);
	else if ((top->index > top->prev->index) && (top->prev->index > bottom->index))
	{
		do_sa(stack_a);
		do_rra(stack_a);
	}
	else if ((top->index > bottom->index) && (bottom->index > top->prev->index))
		do_ra(stack_a);
	else if ((top->prev->index > bottom->index) && (bottom->index > top->index))
	{
		do_sa(stack_a);
		do_ra(stack_a);
	}
	else if ((top->prev->index > top->index) && (top->index > bottom->index))
		do_rra(stack_a);
	else
		return ;
}

// void	sort_over_four_elem(t_stack *stack_a, t_stack *stack_b)
// {
	
// }

void	sort_small_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_size(stack_b) == 0)
		stack_b = NULL;
	else if (stack_size(stack_a) == 1)
		return ;
	else if (stack_size(stack_a) == 2)
		sort_two_elem(stack_a);
	else if (stack_size(stack_a) == 3)
		sort_three_elem(stack_a);
	// else if (stack_size(stack_a) >= 4 && stack_size(stack_a) <= 6)
	// 	sort_over_four_elem(stack_a, stack_b);
}
