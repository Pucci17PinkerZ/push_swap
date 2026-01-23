/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 17:15:01 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/01/23 14:50:44 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

push_b_to_a(t_stacks *stacks)
{
	node_position(a)
	node_position(b);
	while (stack_size(a) != 0)
	{
		find_min_max(stacks);
		find_all_target_2(stacks);
		all_push_cost(stacks);
		find_cheapest();
		push_to_top(stacks);
		do_push();//not done
	}
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

void	all_push_cost(t_stacks *stacks)
{
	t_node	*next_node;

	next_node = stacks->head_b;
	while (next_node->next)
	{
		node_position(stacks->head_a);
		node_position(stacks->head_b);
		next_node->cost = push_cost(next_node, next_node->target,
				stacks->a_len, stacks->b_len);
		next_node = next_node->next;
	}
}

int	push_cost(t_node *node_b, t_node *target, int a_len, int b_len)
{
	int	cost;
	int	median_a;
	int	median_b;

	median_a = a_len / 2;
	median_b = b_len / 2;
	if (node_b->pos <= median_b && target->pos <= median_a)
		cost = bigger_pos(node_b->pos, target->pos);
	else if (node_b->pos > median_b && target->pos > median_a)
		cost = bigger_pos(b_len - node_b->pos, a_len - target->pos);
	else if (node_b->pos > median_b && target->pos <= median_a)
		cost = (b_len - node_b->pos) + target->pos;
	else
		cost = node_b->pos + (a_len - target->pos);
	return (cost);
}

int	bigger_pos(int node_a_pos, int node_b_pos)
{
	
}