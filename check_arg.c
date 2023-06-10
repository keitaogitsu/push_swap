/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kogitsu <kogitsu@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 22:35:45 by kogitsu           #+#    #+#             */
/*   Updated: 2023/06/09 22:36:23 by kogitsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_flow_check(size_t num, int minus_flag, size_t n)
{
	size_t	ov_div;
	size_t	ov_mod;

	ov_div = INT_MAX / 10;
	ov_mod = INT_MAX % 10;
	if ((!minus_flag) && ((num > ov_div) || (num == ov_div && n > ov_mod)))
		return (1);
	else if (minus_flag && \
			((num > ov_div) || (num == ov_div && n > ov_mod + 1)))
		return (1);
	else
		return (0);
}

int	check_arg(char *str)
{
	int		i;
	size_t	num;
	int		minus_flag;

	i = 0;
	minus_flag = 0;
	num = 0;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			minus_flag = 1;
	while (ft_isdigit(str[i]))
	{
		if (ft_flow_check(num, minus_flag, (size_t)(str[i] - '0')))
			return (1);
		else
			num = num * 10 + (str[i++] - '0');
	}
	if (str[i] != '\0' && !ft_isdigit(str[i]))
		return (1);
	return (0);
}