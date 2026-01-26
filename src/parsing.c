/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 10:57:06 by nfiora-d          #+#    #+#             */
/*   Updated: 2026/01/26 12:13:18 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_input(int ac, char **av, t_node *a, t_stacks *stacks)
{
	char **arg_list;

	if (ac != 2)
		return (1);
	arg_list = ft_split(av[2], ' ');
	if (!arg_list)
		return (1);
	if (check_args(arg_list, a))
		return (free_tab(arg_list), clean_exit(stacks) 1);


	return (0);
}

int	check_args(char **arg_list, t_node *a)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = 0;
	while (arg_list[i])
	{
		if (check_nbr(arg_list[i]))
			return ( 1);
		nbr = ft_atoi(arg_list[i]);
		//check si atoi échoue
		set_node(a, nbr);
		check_doubles();
		//check_max_range();
		i++;
	}
	return (0);
}
int	check_doubles(t_stacks *stacks)
{
	t_node	*checked_node;
	t_node	*head_check;
	
	if (!stacks || !stacks->head_a->next)
		return (0);
	head_check = stacks->head_a;
	while(head_check)
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
		if (!(ft_isdigit(arg[j]) || arg[j] == '-'))//checker comment faire pour "--"
			return (1);
		j++;
	}
	if (arg[j - 1] == '-')
		return (1);
	return (0);
}

int	set_node(t_node *a, int nbr)
{
	t_node	*end_node;
	t_node	*new_node;

	if (a->next == NULL)
	{
		a->nbr = nbr;
		a->pos = 0;
	}
	else
	{
		end_node = last_node(a);
		new_node = malloc(sizeof(t_node));
		if (!new_node)
			return (1);
		new_node->nbr = nbr;
		new_node->pos = end_node->pos + 1;
		end_node->next = new_node;
	}
	return (0);
}

t_node	*last_node(t_node *a)
{
	t_node	*final_node;
	t_node	*tmp;
	
	if (!a)
		return (NULL);
	tmp = a;
	while (tmp->next)
	{
		final_node = tmp->next;
		tmp = final_node;
	}
	return (tmp);
}
