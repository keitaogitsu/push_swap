/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 10:43:13 by kogitsu           #+#    #+#             */
/*   Updated: 2023/06/03 20:06:19 by kogitsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int val)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->prev = NULL;
	node->next = NULL;
	node->index = 0;
	node->cc_flag = 0;
	node->value = val;
	return (node);
}

void	create_stack(t_stack *stack)
{
	t_node	*dummy;

	dummy = (t_node *)malloc(sizeof(t_node));
	if (dummy == NULL)
		return ;
	dummy->next = dummy;
	dummy->prev = dummy;
	dummy->index = -1;
	stack->sentry = dummy;
}

int	add_node_next_sentry(t_stack *stack, t_node *new_node)
{
	if (new_node == NULL)
		return (1);
	new_node->next = stack->sentry->next;
	new_node->prev = stack->sentry;
	new_node->next->prev = new_node;
	stack->sentry->next = new_node;
	return (0);
}

int	add_node_prev_sentry(t_stack *stack, t_node *new_node)
{
	if (new_node == NULL)
		return (1);
	new_node->prev = stack->sentry->prev;
	new_node->next = stack->sentry;
	new_node->prev->next = new_node;
	stack->sentry->prev = new_node;
	return (0);
}

int	stack_size(t_stack *stack)
{
	int		count;
	t_node	*tmp_node;

	if (stack == NULL)
		return (0);
	if (stack->sentry->next == stack->sentry && \
		stack->sentry->prev == stack->sentry)
		return (0);
	else
	{
		count = 0;
		tmp_node = stack->sentry;
		while (tmp_node->next != stack->sentry)
		{
			count++;
			tmp_node = tmp_node->next;
		}
		return (count);
	}
}
