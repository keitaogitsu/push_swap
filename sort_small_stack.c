/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:34:24 by kogitsu           #+#    #+#             */
/*   Updated: 2023/06/10 11:20:14 by kogitsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
