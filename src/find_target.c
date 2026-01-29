/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_target.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:23:36 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/01/29 13:26:03 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// void	find_all_target(t_stacks *stacks)
// {
// 	t_node	*next_node;

// 	next_node = stacks->head_a;
// 	while (next_node->next)
// 	{
// 		next_node->target = find_target_b(stacks->head_b,
// 				next_node->nbr, stacks->max_b);
// 		next_node = next_node->next;
// 	}
// 	return ;
// }

// t_node	*find_target_b(t_node *b, int nbr, t_node *max_a)
// {
// 	t_node	*actual_smaller;
// 	t_node	*target;

// 	actual_smaller = b;
// 	target = NULL;
// 	while (actual_smaller->next)
// 	{
// 		if (nbr > actual_smaller->nbr)
// 		{
// 			if (!target)
// 				target = actual_smaller;
// 			else if (actual_smaller->nbr < target->nbr)
// 				target = actual_smaller;
// 		}
// 		actual_smaller = actual_smaller->next;
// 	}
// 	if (!target)
// 		target = max_a;
// 	return (target);
// }



void	find_all_target(t_stacks *stacks)
{
	t_node	*curr;

	curr = stacks->head_a;
	while (curr) // Parcourir jusqu'au bout
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
	while (actual_node) // Assure-toi de parcourir TOUTE la liste
	{
		if (nbr > actual_node->nbr)
		{
			// On cherche le "plus grand" parmi les plus petits
			if (!target || actual_node->nbr > target->nbr)
				target = actual_node;
		}
		actual_node = actual_node->next;
	}
	// Si aucun n'est plus petit, la cible est le max de B
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
	t_node	*target;

	target = NULL;
	while (a) // On parcourt TOUT A, sans s'arrêter au dernier ->next
	{
		if (nbr < a->nbr)
		{
			// On cherche le PLUS PETIT des chiffres PLUS GRANDS
			if (!target || a->nbr < target->nbr)
				target = a;
		}
		a = a->next;
	}
	if (!target)
		target = min_a;
	return (target);
}

t_node	*find_cheapest(t_stacks *stacks)
{
	t_node	*cheapest;
	t_node	*curr;

	if (!stacks->head_b)
		return (NULL);
	cheapest = stacks->head_b;
	curr = stacks->head_b;
	while (curr)
	{
		if (curr->cost < cheapest->cost)
			cheapest = curr;
		if (cheapest->cost == 0) // Optimisation : on ne trouvera pas mieux
			return (cheapest);
		curr = curr->next;
	}
	return (cheapest);
}
