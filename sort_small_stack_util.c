/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack_util.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 18:10:49 by kogitsu           #+#    #+#             */
/*   Updated: 2023/06/03 20:14:32 by kogitsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two_elem(t_stack *stack)
{
	if (stack->sentry->next->index < stack->sentry->prev->index)
		do_sa(stack);
}

void	sort_three_elem_a(t_stack *stack_a)
{
	t_node	*top;
	t_node	*bottom;
	t_node	*middle;

	top = stack_a->sentry->prev;
	bottom = stack_a->sentry->next;
	middle = bottom->next;
	if ((bottom->index > top->index) && (top->index > middle->index))
		do_sa(stack_a);
	else if ((top->index > middle->index) && (middle->index > bottom->index))
	{
		do_sa(stack_a);
		do_rra(stack_a);
	}
	else if ((top->index > bottom->index) && (bottom->index > middle->index))
		do_ra(stack_a);
	else if ((middle->index > bottom->index) && (bottom->index > top->index))
	{
		do_sa(stack_a);
		do_ra(stack_a);
	}
	else if ((middle->index > top->index) && (top->index > bottom->index))
		do_rra(stack_a);
	else
		return ;
}

void	r_sort_three_elem_b(t_stack *stack_b)
{
	t_node	*top;
	t_node	*bottom;
	t_node	*middle;

	top = stack_b->sentry->prev;
	bottom = stack_b->sentry->next;
	middle = bottom->next;
	if ((bottom->index > middle->index) && (middle->index > top->index))
	{
		do_sb(stack_b);
		do_rrb(stack_b);
	}
	else if ((middle->index > bottom->index) && (bottom->index > top->index))
		do_rb(stack_b);
	else if ((bottom->index > top->index) && (top->index > middle->index))
		do_rrb(stack_b);
	else if ((middle->index > top->index) && (top->index > bottom->index))
		do_sb(stack_b);
	else if ((top->index > bottom->index) && (bottom->index > middle->index))
	{
		do_sb(stack_b);
		do_rb(stack_b);
	}
	else
		return ;
}

void	sort_b_and_push_a(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_size(stack_b) == 1)
		do_pa(stack_a, stack_b);
	else if (stack_size(stack_b) == 2)
	{
		if (stack_b->sentry->next->index > stack_b->sentry->prev->index)
			do_sb(stack_b);
		do_pa(stack_a, stack_b);
		do_pa(stack_a, stack_b);
	}
	else if (stack_size(stack_b) == 3)
	{
		r_sort_three_elem_b(stack_b);
		while (stack_size(stack_a) != 6)
			do_pa(stack_a, stack_b);
	}
	else
		return ;
}

void	sort_over_four_elem(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*top_a;
	int		start_a_size;

	start_a_size = stack_size(stack_a);
	while (stack_size(stack_a) > 3)
	{
		top_a = stack_a->sentry->prev;
		if (top_a->index < (start_a_size - 3))
			do_pb(stack_a, stack_b);
		else
		{
			// if (judge_rotate_or_rrotate(stack_a, 0, 2))
			// 	do_ra(stack_a);
			// else
			do_ra(stack_a);
		}
	}
	sort_three_elem_a(stack_a);
	sort_b_and_push_a(stack_a, stack_b);
}

//  4 3 1 0 5 2
//  
