/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 22:21:34 by kogitsu           #+#    #+#             */
/*   Updated: 2023/07/01 15:02:06 by kogitsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// #include <libc.h>

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q push_swap");
// }

// char	*my_malloc(int size)
// {
// 	size++;
// 	return (NULL);
// }

void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_size(stack_a) <= 6)
		sort_small_stack(stack_a, stack_b);
	else
		sort_big_stack(stack_a, stack_b);
}

int	check_add(char *arg, t_stack *stack_a, t_stack *stack_b)
{
	if (check_arg(arg))
	{
		ft_putstr_fd("Error\n", 2);
		free_stack(stack_a, stack_b);
		exit(1);
	}
	else
	{
		if (add_node_next_sentry(stack_a, create_node(ft_atoi(arg))))
			free_stack(stack_a, stack_b);
		return (0);
	}
}

int	arg_check_add(int argc, char **argv, t_stack *stack_a, t_stack *stack_b)
{
	char	**container;
	int		i;
	int		j;

	i = 0;
	while (++i < argc)
	{
		container = ft_split(argv[i], ' ');
		if (container == NULL || container[0] == NULL)
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		j = 0;
		while (container[j] != NULL)
		{
			if (check_add(container[j++], stack_a, stack_b))
			{
				free_container_content(container);
				return (1);
			}
		}
		free_container_content(container);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc < 2)
		return (1);
	create_stack(&stack_a);
	create_stack(&stack_b);
	if (arg_check_add(argc, argv, &stack_a, &stack_b))
		return (1);
	if (check_duplicate(&stack_a))
	{
		ft_putstr_fd("Error\n", 2);
		free_stack(&stack_a, &stack_b);
		return (1);
	}
	c_compression(&stack_a);
	if (!is_sorted(&stack_a))
		sort_stack(&stack_a, &stack_b);
	free_stack(&stack_a, &stack_b);
	return (0);
}
