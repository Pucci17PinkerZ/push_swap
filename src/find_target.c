/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_target.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:23:36 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/01/29 15:27:06 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	find_all_target(t_stacks *stacks)
{
	t_node	*curr;

	curr = stacks->head_a;
	while (curr)
	{
		curr->target = find_target_b(stacks->head_b, curr->nbr, stacks->max_b);
		curr = curr->next;
	}
}

t_node	*find_target_b(t_node *b, int nbr, t_node *max_b)
{
	t_node	*actual_node;
	t_node	*target;

	actual_node = b;
	target = NULL;
	while (actual_node)
	{
		if (nbr > actual_node->nbr)
		{
			if (!target || actual_node->nbr > target->nbr)
				target = actual_node;
		}
		actual_node = actual_node->next;
	}
	if (!target)
		target = max_b;
	return (target);
}
void	find_all_target_2(t_stacks *stacks)
{
	t_node	*curr;

	curr = stacks->head_b;
	while (curr) // On traite chaque élément de B
	{
		curr->target = find_target_a(stacks->head_a,
				curr->nbr, stacks->min_a);
		curr = curr->next;
	}
}

t_node	*find_target_a(t_node *a, int nbr, t_node *min_a)
{
	t_node	*target = NULL;

	while (a) // Parcourt toute la liste
	{
		if (nbr < a->nbr)
		{
			// On cherche le PLUS PETIT des chiffres PLUS GRANDS
			if (!target || a->nbr < target->nbr)
				target = a;
		}
		a = a->next;
	}
	return (target ? target : min_a);
}

t_node	*find_cheapest(t_stacks *stacks)
{
	t_node	*cheapest = stacks->head_b;
	t_node	*curr = stacks->head_b;

	while (curr)
	{
		if (curr->cost < cheapest->cost)
			cheapest = curr;
		if (cheapest->cost == 0)
			return (cheapest);
		curr = curr->next;
	}
	return (cheapest);
}
