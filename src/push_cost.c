/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:22:07 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/02/02 00:28:15 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	all_push_cost(t_stacks *stacks)
{
	t_node	*next_node;

	next_node = stacks->head_a;
	while (next_node)
	{
		node_position(stacks, 'a');
		node_position(stacks, 'b');
		stacks->a_len = stack_size(stacks->head_a);
		stacks->b_len = stack_size(stacks->head_b);
		next_node->cost = push_cost(next_node, next_node->target,
				stacks->a_len, stacks->b_len);
		next_node = next_node->next;
	}
	return ;
}

int	push_cost(t_node *node_a, t_node *target, int a_len, int b_len)
{
	int	cost;
	int	median_a;
	int	median_b;

	median_a = a_len / 2;
	median_b = b_len / 2;
	if (node_a->pos <= median_a && target->pos <= median_b)
		cost = bigger_pos(node_a->pos, target->pos);
	else if (node_a->pos > median_a && target->pos > median_b)
		cost = bigger_pos(a_len - node_a->pos, b_len - target->pos);
	else if (node_a->pos > median_a && target->pos <= median_b)
		cost = (a_len - node_a->pos) + target->pos;
	else
		cost = node_a->pos + (b_len - target->pos);
	return (cost);
}

int	bigger_pos(int node_a_pos, int node_b_pos)
{
	if (node_a_pos < node_b_pos)
		return (node_b_pos);
	else
		return (node_a_pos);
}
