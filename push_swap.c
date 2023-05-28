/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 22:21:34 by kogitsu           #+#    #+#             */
/*   Updated: 2023/05/28 21:19:42 by kogitsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack_a, t_stack *stack_b)
{
	int		count_a;
	int		count_b;
	t_node	*current_a;
	t_node	*current_b;

	count_a = stack_size(stack_a);
	count_b = stack_size(stack_b);
	current_a = stack_a->sentry->prev;
	current_b = stack_b->sentry->prev;
	if (count_a >= count_b)
	{
		while (count_a--)
		{
			ft_printf("%d | %d", current_a->value, current_b->value);
			current_a = current_a->prev;
			current_b = current_b->prev;
			ft_printf("\n");
		}
		ft_printf("-----\na   b\n");
	}
	else
	{
		while (count_b--)
		{
			ft_printf("%d | %d", current_a->value, current_b->value);
			current_a = current_a->prev;
			current_b = current_b->prev;
			ft_printf("\n");
		}
		ft_printf("-----\na | b\n");
	}
	ft_printf("\n");
}

int	check_num(char *str)
{
	int	i;
	int	strlen;

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

int	main(int argc, char *argv[])
{
	int		i;
	int		tmp;
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc < 2)
		return (0);
	i = 1;
	create_stack(&stack_a);
	create_stack(&stack_b);
	while (i < argc)
	{
		if (check_num(argv[i]))
		{
			ft_printf("Error\n");
			return (0);
		}
		else
		{
			tmp = ft_atoi(argv[i]);
			if (add_node_next_sentry(&stack_a, create_node(tmp)))
				free_content(&stack_a);
		}
		i++;
	}
	print_stack(&stack_a, &stack_b);
	push(&stack_b, &stack_a);
	print_stack(&stack_a, &stack_b);
	double_swap(&stack_a, &stack_b);
	print_stack(&stack_a, &stack_b);
	rotate(&stack_a);
	print_stack(&stack_a, &stack_b);
	r_rotate(&stack_a);
	print_stack(&stack_a, &stack_b);
	return (0);
}
