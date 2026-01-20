/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 10:57:06 by nfiora-d          #+#    #+#             */
/*   Updated: 2026/01/20 19:14:13 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int ac, char **av)
{
	t_node	a;
	t_node	b;

	ft_bzero(&a, sizeof(t_node));
	ft_bzero(&b, sizeof(t_node));
	if (check_input(ac, av, &a))
		return (1);
	if (check_doubles(&a))
		return (supprimer les stack car impossible);
	if (sort_node(&a, &b))
		return (1);
	return (0);
}

int	sort_node(t_node *a, t_node *b)
{
	int	node_left;

	node_left = stack_size(a);
	if()//checker si c'est déjà dans l'ordre
	if (node_left > 3)
		{
			pa(a, b);
			pa(a, b);
		}
	while (stack_size(a) != 3)
	{
		//fonction qui trouve le min et max
		//il doit stocker sa qqpart

		
		//calculer le cost de chaque move$
		//
	}
	
}

void	node_position(t_node *a)
{
	t_node	*next_node;
	t_node	*tmp;

	tmp = a;
	tmp->pos = 1;
	while(tmp->next)
	{
		next_node = tmp->next;
		next_node->pos++;
		tmp = next_node;
	}
	return ;
}

int	is_node_sorted(t_node *a)
{
	t_node	*tmp;
	t_node	*big;
	t_node	*low;

	low = a;
	big = low->next;
	while(big->next)
	{
		if (low->nbr < big->nbr)
		{
			tmp = big;
			low = big;
			big = tmp->next;
		}
		else
			return (1);
	}
	return (0);
}