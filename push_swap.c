/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 22:21:34 by kogitsu           #+#    #+#             */
/*   Updated: 2023/06/20 23:30:26 by kogitsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	print_stack(t_stack *stack_a, t_stack *stack_b)
// {
// 	int		count_a;
// 	int		count_b;
// 	t_node	*current_a;
// 	t_node	*current_b;

// 	count_a = stack_size(stack_a);
// 	count_b = stack_size(stack_b);
// 	current_a = stack_a->sentry->prev;
// 	current_b = stack_b->sentry->prev;
// 	if (count_a >= count_b)
// 	{
// 		while (count_a)
// 		{
// 			if (count_a > count_b)
// 			{
// 				ft_printf("%d[%d] |   \n", current_a->value, current_a->index);
// 				current_a = current_a->prev;
// 				count_a--;
// 			}
// 			else
// 			{
// 				ft_printf("%d[%d] | %d[%d]\n", current_a->value, 
// 				current_a->index,current_b->value,current_b->index);
// 				current_a = current_a->prev;
// 				current_b = current_b->prev;
// 				count_a--;
// 			}
// 		}
// 		ft_printf("----------\n a   | b\n");
// 	}
// 	else
// 	{
// 		while (count_b)
// 		{
// 			if (count_b > count_a)
// 			{
// 				ft_printf("     | %d[%d]\n", current_b->value,current_b->index);
// 				current_b = current_b->prev;
// 				count_b--;
// 			}
// 			else
// 			{
// 				ft_printf("%d[%d] | %d[%d]\n", current_a->value, 
// 				current_a->index,current_b->value,current_b->index);
// 				current_a = current_a->prev;
// 				current_b = current_b->prev;
// 				count_b--;
// 			}
// 		}
// 		ft_printf("----------\n a   | b\n");
// 	}
// 	ft_printf("\n");
// }

#include <libc.h>

__attribute__((destructor))
static void destructor() {
    system("leaks -q push_swap");
}

void	free_stack(t_stack *stack_a, t_stack *stack_b)
{
	free_content(stack_a);
	free_content(stack_b);
}

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
		ft_printf("Error\n");
		free_stack(stack_a, stack_b);
		return (1);
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
	j = 1;
	container = NULL;
	if (argc == 2)
	{
		container = ft_split(argv[1], ' ');
		while (container[i] != NULL)
		{
			if (check_add(container[i++], stack_a, stack_b))
			{
				free_container_content(container);
				return (1);
			}
		}
		free_container_content(container);
	}
	else
	{
		while (j < argc)
			if (check_add(argv[j++], stack_a, stack_b))
				return (1);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc < 2)
		return (0);
	create_stack(&stack_a);
	create_stack(&stack_b);
	if (arg_check_add(argc, argv, &stack_a, &stack_b))
		return (0);
	if (check_duplicate(&stack_a))
	{
		ft_printf("Error\n");
		free_stack(&stack_a, &stack_b);
		return (0);
	}
	c_compression(&stack_a);
	if (!is_sorted(&stack_a))
		sort_stack(&stack_a, &stack_b);
	free_stack(&stack_a, &stack_b);
	return (0);
}
