/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 10:57:06 by nfiora-d          #+#    #+#             */
/*   Updated: 2026/01/29 16:31:04 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_input(char **av, t_stacks *stacks)
{
	char	**arg_list;

	arg_list = NULL;
	arg_list = new_args_list(av, NULL);
	if (!arg_list)
		return (1);
	if (check_args(arg_list, stacks))
		return (free_tab(arg_list, 0), clean_exit(stacks), 1);
	return (free_tab(arg_list, 0), 0);
}

int	check_args(char **arg_list, t_stacks *stacks)
{
	int			i;
	long long	nbr;

	i = 0;
	nbr = 0;
	while (arg_list[i])
	{
		if (check_nbr(arg_list[i]))
			return (1);
		nbr = ft_atoll(arg_list[i]);
		if (nbr > 2147483647 || nbr < -2147483648)
			return (1);
		if (set_node(stacks, (int)nbr))
			return (1);
		if (check_doubles(stacks))
			return (1);
		i++;
	}
	return (0);
}

long long	ft_atoll(const char *nptr)
{
	long long	i;
	long		sign;
	long long	res;

	i = 0;
	sign = 1;
	res = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
	{
		i++;
	}
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	return (res * sign);
}

int	check_doubles(t_stacks *stacks)
{
	t_node	*checked_node;
	t_node	*head_check;

	head_check = stacks->head_a;
	while (head_check)
	{
		checked_node = head_check->next;
		while (checked_node)
		{
			if (head_check->nbr == checked_node->nbr)
				return (1);
			checked_node = checked_node->next;
		}
		head_check = head_check->next;
	}
	return (0);
}

int	check_nbr(char *arg)
{
	int	j;

	j = 0;
	while (arg[j])
	{
		if (!(ft_isdigit(arg[j]) || arg[j] == '-' || arg[j] == '+'))
			return (1);
		if (arg[j] == '-' && arg[j + 1] == '-')
			return (1);
		if (arg[j] == '+' && arg[j + 1] == '+')
			return (1);
		j++;
	}
	if (arg[j - 1] == '-' || arg[j - 1] == '+')
		return (1);
	return (0);
}
