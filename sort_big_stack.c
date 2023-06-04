/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 14:25:16 by kogitsu           #+#    #+#             */
/*   Updated: 2023/06/04 14:54:59 by kogitsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_ra_or_pb(int i, t_stack *stack_a, t_stack *stack_b)
{
	int	num;

	num = stack_a->sentry->prev->index;
	if (((num >> i) & 1) == 1)
		do_ra(stack_a);
	else
		do_pb(stack_a, stack_b);
}

void	sort_big_stack(t_stack *stack_a, t_stack *stack_b)
{
	int	size;
	int	max_num;
	int	max_bits;
	int	i;
	int	j;

	size = stack_size(stack_a);
	max_num = size - 1;
	max_bits = 0;
	i = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			do_ra_or_pb(i, stack_a, stack_b);
			j++;
		}
		while (stack_size(stack_b) != 0)
			do_pa(stack_a, stack_b);
		i++;
	}
}
