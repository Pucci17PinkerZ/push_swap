/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 19:08:09 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/02/02 04:32:39 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	**new_args_list(char **av, char **args)
{
	int	nbr_arg;

	nbr_arg = 0;
	nbr_arg = count_args(av, 0);
	args = assign_args(nbr_arg, av, NULL);
	if (!args)
		return (NULL);
	return (args);
}

char	**assign_args(int i, char **av, char **catcher)
{
	int		a;

	a = 0;
	catcher = malloc(sizeof(char *) * (i + 1));
	if (!catcher)
		return (NULL);
	i = 0;
	while (av[a])
	{
		if (append_args(catcher, av[a], &i))
		{
			catcher[i] = NULL;
			free_tab(catcher, 0);
			return (NULL);
		}
		a++;
	}
	catcher[i] = NULL;
	return (catcher);
}

int	append_args(char **catcher, char *str, int *i)
{
	char	**args;
	int		s;

	args = ft_split(str, ' ');
	if (!args)
		return (1);
	s = 0;
	while (args[s])
	{
		catcher[*i] = ft_strdup(args[s]);
		if (!catcher[*i])
		{
			free_tab(args, 0);
			return (1);
		}
		(*i)++;
		s++;
	}
	free_tab(args, 0);
	return (0);
}

int	count_args(char **av, int nbr_arg)
{
	int		i;
	int		s;
	char	**args;

	i = 0;
	while (av[i])
	{
		s = 0;
		args = ft_split(av[i], ' ');
		while (args[s])
		{
			s++;
		}
		nbr_arg += s;
		free_tab(args, 0);
		i++;
	}
	return (nbr_arg);
}
