/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 22:21:34 by kogitsu           #+#    #+#             */
/*   Updated: 2023/06/04 15:12:33 by kogitsu          ###   ########.fr       */
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
// 				ft_printf("%d[%d] | %d[%d]\n", current_a->value,current_a->index,current_b->value,current_b->index);
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
// 				ft_printf("%d[%d] | %d[%d]\n", current_a->value,current_a->index,current_b->value,current_b->index);
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

int	check_num(char *str)
{
	int	i;
	int	strlen;

	i = 0;
	strlen = ft_strlen(str);
	while (i < strlen)
	{
		if (str[0] != '+' && str[0] != '-')
		{
			if (!ft_isdigit(str[i]))
				return (1);
		}
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
			free_content(&stack_a);
			free_content(&stack_b);
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
	c_compression(&stack_a);
	if (stack_size(&stack_a) <= 6)
		sort_small_stack(&stack_a, &stack_b);
	else
		sort_big_stack(&stack_a, &stack_b);
	free_content(&stack_a);
	free_content(&stack_b);
	return (0);
}
