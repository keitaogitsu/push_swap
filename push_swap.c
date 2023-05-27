/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 22:21:34 by kogitsu           #+#    #+#             */
/*   Updated: 2023/05/27 23:58:26 by kogitsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int val)
{
	t_node	*node;

	node = (t_node*)malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->prev = NULL;
	node->next = NULL;
	node->value = val;
	// node->index = 0:
	return (node);
}

void	create_stack(t_stack *stack) {
	t_node *dummy = (t_node*)malloc(sizeof(t_node));
	if (dummy == NULL)
		return ;
	dummy->next = dummy;
	dummy->prev = dummy;
	stack->sentry = dummy;
}

void	add_node(t_stack *stack, int num)
{
	t_node	*new_node;
	
	new_node = create_node(num);
	new_node->next = stack->sentry->next;
	new_node->prev = stack->sentry;
	stack->sentry->next->prev = new_node;
	stack->sentry->next = new_node;
}

void print_list(t_stack *stack) {
  	t_node *current;

	current = stack->sentry->prev;
	while (current != stack->sentry) 
	{
		ft_printf("%d ", current->value);
		current = current->prev;
	}
	ft_printf("\n");
}

int	check_num(char *str)
{
	int i;
	int strlen;

	i = 0;
	strlen = ft_strlen(str);
	while (i < strlen)
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int main(int argc, char *argv[])
{
	int	i;
	t_stack	*stack_a;
	t_stack	*stack_b;
	

	if (argc < 2)
		return (0);
	i = 1;
	stack_a = (t_stack*)malloc(sizeof(t_stack));
	stack_b = (t_stack*)malloc(sizeof(t_stack));
	create_stack(stack_a);
	create_stack(stack_b);
	while (i < argc)
	{
		if (check_num(argv[i]))
		{
			ft_printf("Error\n");
			return (0);
		}
		else
			add_node(stack_a, ft_atoi(argv[i]));
		i++;
	}
	print_list(stack_a);
	free(stack_a);
	free(stack_b);
	return (0);
}
