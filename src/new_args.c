/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 19:08:09 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/01/27 19:28:25 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	**new_args_list(char **av, char **args)
{
	int	nbr_arg;
	
	nbr_arg = 0;
	nbr_arg = count_args(av, 0);

	args = assign_args(nbr_arg, 0, av, NULL);
	if (!args)
		return (NULL);
	return (args);
}

char	**assign_args(int i, int s, char **av, char	**catcher)
{
	int		a;
	char	**args;

	a = 0;
	catcher = malloc(sizeof(char *) * (i + 1));
	if (!catcher)
		return (NULL);
	i = 0;
	while(av[a])
	{
		s = 0;
		args = ft_split(av[a], ' ');
		if (!args)
			return (NULL);
		while (args[s])
		{
			catcher[i] = ft_strdup(args[s]);
			i++;
			s++;
		}
		free_tab(args, 0);
		a++;
	}
	catcher[i] = NULL;
	return (catcher);
}

int	count_args(char **av, int nbr_arg)
{
	int	i;
	int	s;
	char	**args;

	i = 0;
	while(av[i])
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
