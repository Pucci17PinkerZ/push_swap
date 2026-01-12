/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfiora-d <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 10:57:06 by nfiora-d          #+#    #+#             */
/*   Updated: 2025/10/03 12:43:43 by nfiora-d         ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	// checker ce qui rentre

	t_node	a;
	t_node	b;

	ft_bzero(&a, sizeof(t_node));
	ft_bzero(&b, sizeof(t_node));
	if (check_intput(ac, av, &a))
		return (1);

	return (0);
}

int	check_input(int ac, char **av, t_node *a)
{
	char **arg_list;

	if (ac != 2)
		return (1);
	arg_list = ft_split(av[2], ' ');
	if (!arg_list)
		return (1);
	if (check_args(arg_list, a))
		return (1);


	return (0);
}

int	check_args(char **arg_list, t_node *a)
{
	int	i;

	i = 0;
	while (arg_list[i])
	{
		if (check_nbr(arg_list[i]))
			return (1);
		
		i++;
	}
}

int	check_nbr(char *arg)
{
	int	j;

	j = 0;
	while (arg[j])
	{
		if(!(ft_isdigit(arg[j]) || arg[j] == '-'))//checker comment faire pour "--"
			return (1);
		j++;
	}
	return (0);
}