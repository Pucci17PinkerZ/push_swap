/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 10:57:06 by nfiora-d          #+#    #+#             */
/*   Updated: 2026/01/22 12:46:42 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int ac, char **av)
{
	t_node	a;
	t_node	b;
	t_stacks	stacks;
	
	stack.head_a = a;
	stack.head_b = b;
	if (check_input(ac, av, &stacks.a))
		return (1);
	if (check_doubles(&stacks.a))
		return (supprimer les stack car impossible);
	if (sort_node(&stacks))
		return (1);
	return (0);
}

int	sort_node(t_stacks * stacks)
{
	if(check_stack_order())//checker si c'est déjà dans l'ordre

	while (check_stack_order(stacks->head_a))
	{
		//fonction qui trouve le min et max
		//il doit stocker sa qqpart
		push_a_to_b(stacks);
		push_b_to_a(stacks);
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