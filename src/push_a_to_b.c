/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 17:14:57 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/01/25 19:41:45 by pucci17pink      ###   ########.fr       */
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

	while (target->pos != 0)
	{
		median = find_median(stack_size);
		if (target->pos <= median)
			rb(stacks->head_b);
		else
			rrb(stacks->head_b);
	}
	return ;
}

int	find_median(int stack_size)
{
	median = stack_size / 2;
	return (median);
}