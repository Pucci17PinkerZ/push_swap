/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_target.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:23:36 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/01/25 13:58:48 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	find_all_target(t_stacks *stacks)
{
	t_node	*next_node;

	next_node = stacks->head_a;
	while (next_node->next)
	{
		next_node->target = find_target_b(stacks->head_b,
				next_node->nbr, stacks->max_b);
		next_node = next_node->next;
	}
	return ;
}

t_node	*find_target_b(t_node *b, int nbr, t_node *max_a)
{
	t_node	*actual_smaller;
	t_node	*target;

	actual_smaller = b;
	target = NULL;
	while (actual_smaller->next)
	{
		if (nbr > actual_smaller->nbr)
		{
			if (!target)
				target = actual_smaller;
			else if (actual_smaller->nbr < target->nbr)
				target = actual_smaller;
		}
		actual_smaller = actual_smaller->next;
	}
	if (!target)
		target = max_a;
	return (target);
}

void	find_all_target_2(t_stacks *stacks)////////////a modifier!!!!!!!!!!!!!
{
	t_node	*next_node;

	next_node = stacks->head_b;
	while (next_node->next)
	{
		next_node->target = find_target_a(stacks->head_a,
				next_node->nbr, stacks->min_a);
		next_node = next_node->next;
	}
	return ;
}

t_node	*find_target_a(t_node *b, int nbr, t_node *min_a)
{
	t_node	*actual_bigger;
	t_node	*target;

	actual_bigger = b;
	target = NULL;
	while (actual_bigger->next)
	{
		if (nbr < actual_bigger->nbr)
		{
			if (!target)
				target = actual_bigger;
			else if (actual_bigger->nbr > target->nbr)
				target = actual_bigger;
		}
		actual_bigger = actual_bigger->next;
	}
	if (!target)
		target = min_a;
	return (target);
}

t_node	*find_cheapest(t_stacks *stacks)
{
	t_node	*cheapest;
	t_node	*next_node
	
	cheapest = stacks->head_b;
	if (stacks->head_b->next == NULL)
		return (cheapest);
	next_node = cheapest->next;
	while (next_node->next)
	{
		if (cheapest->cost == 0)
			return (cheapest);
		if (cheapest->cost > next_node->cost)
			cheapest = next_node;
		next_node = next_node->next;
	}
	return (cheapest);
}
