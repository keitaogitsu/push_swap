/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 07:37:33 by kogitsu           #+#    #+#             */
/*   Updated: 2023/05/28 20:37:33 by kogitsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_node
{
	int				value;
	// int				index;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*sentry;
}	t_stack;

t_node	*create_node(int val);
void	create_stack(t_stack *stack);
int		add_node_next_sentry(t_stack *stack, t_node *new_node);
int		add_node_prev_sentry(t_stack *stack, t_node *new_node);
int		stack_size(t_stack *stack);
void	free_content(t_stack *stack);
void	swap(t_stack *stack);
void	double_swap(t_stack *stack_a, t_stack *stack_b);
void	rotate(t_stack *stack);
void	double_rotate(t_stack *stack_a, t_stack *stack_b);
void	r_rotate(t_stack *stack);
void	double_r_rotate(t_stack *stack_a, t_stack *stack_b);
void	push(t_stack *receiving_stack, t_stack *pushing_stack);

#endif