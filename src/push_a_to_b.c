/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 17:14:57 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/01/23 12:29:25 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_a_to_b(t_stacks *stacks)
{
	pb(stacks->head_a, stacks->head_b);
	pb(stacks->head_a, stacks->head_b);
	node_position(a);
	node_position(b);
	while (stack_size(a) != 3)
	{
		node_position(a)
		node_position(b);
		find_min_max(stacks);
		find_all_target(stacks);
		stacks->b_len = stack_size(stacks->head_b);
		push_to_top_b(stacks->head_b, stacks->head_a->target, stacks->b_len);
		pb(stacks->head_a, stacks->head_b);
	}
	sort_three(stacks->head_a);
}

void	push_to_top_b(t_node *head_b, t_node *target, int stack_size)
{
	int	median;

	while (target->pos != 1)
	{
		median = stack_size / 2;
		if (target->pos <= median)
			rb(stacks->head_b);
		else
			rrb(stacks->head_b);
	}
	return ;
}

void	push_cost(t_stacks *stacks)
{
	t_node	*next_node;

	next_node = stacks->head_a;
	while (next_node->next)
	{
		
		next_node = next_node->next;
	}
}

void	find_all_target(t_stacks *stacks)
{
	t_node	*next_node;

	next_node = stacks->head_a;
	while (next_node->next)
	{
		next_node->target = find_target_b(stacks->head_b,
				next_node->nbr, stacks->max_a);
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
		if (nbr < actual_smaller->nbr)
		{
			if (!target)
				target = actual_smaller;
			else if (actual_smaller->nbr > target->nbr)
				target = actual_smaller;
		}
		actual_smaller = actual_smaller->next;
	}
	if (!target)
		target = max_a;
	return (target);
}
