/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_content.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:54:38 by kogitsu           #+#    #+#             */
/*   Updated: 2023/05/28 18:46:17 by kogitsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_content(t_stack *stack)
{
	t_node	*tmp_node;

	while (stack->sentry->next != stack->sentry)
	{
		tmp_node = stack->sentry->next;
		stack->sentry->next = stack->sentry->next->next;
		free(tmp_node);
	}
	free(stack->sentry);
}
