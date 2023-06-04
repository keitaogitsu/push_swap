/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 07:37:33 by kogitsu           #+#    #+#             */
/*   Updated: 2023/06/04 15:03:40 by kogitsu          ###   ########.fr       */
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
	int				index;
	int				cc_flag;
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
void	do_sa(t_stack *stack_a);
void	do_sb(t_stack *stack_b);
void	do_ss(t_stack *stack_a, t_stack *stack_b);
void	rotate(t_stack *stack);
void	do_ra(t_stack *stack_a);
void	do_rb(t_stack *stack_b);
void	do_rr(t_stack *stack_a, t_stack *stack_b);
void	r_rotate(t_stack *stack);
void	do_rra(t_stack *stack_a);
void	do_rrb(t_stack *stack_b);
void	do_rrr(t_stack *stack_a, t_stack *stack_b);
void	push(t_stack *receiving_stack, t_stack *pushing_stack);
void	do_pa(t_stack *stack_a, t_stack *stack_b);
void	do_pb(t_stack *stack_a, t_stack *stack_b);
void	c_compression(t_stack *stack);
void	sort_small_stack(t_stack *stack_a, t_stack *stack_b);
void	sort_two_elem(t_stack *stack);
void	sort_three_elem_a(t_stack *stack_a);
void	r_sort_three_elem_b(t_stack *stack_b);
void	sort_b_and_push_a(t_stack *stack_a, t_stack *stack_b);
void	sort_over_four_elem(t_stack *stack_a, t_stack *stack_b);
int		judge_rotate_or_rrotate(t_stack *stack, int min, int max);
void	sort_big_stack(t_stack *stack_a, t_stack *stack_b);
void	do_ra_or_pb(int i, t_stack *stack_a, t_stack *stack_b);

#endif