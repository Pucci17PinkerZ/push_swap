/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 17:15:01 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/02/02 00:30:41 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_b_to_a(t_stacks *stacks)
{
	while (stack_size(stacks->head_b) != 0)
	{
		node_position(stacks, 'a');
		node_position(stacks, 'b');
		find_min_max(stacks);
		find_all_target_2(stacks);
		stacks->a_len = stack_size(stacks->head_a);
		push_to_top_a(stacks, stacks->head_b->target, stacks->a_len);
		pa(stacks);
	}
	final_sort(stacks);
}

void	final_sort(t_stacks *stacks)
{
	t_node	*node_min;
	int		size;

	size = stack_size(stacks->head_a);
	node_position(stacks, 'a');
	node_min = find_min(stacks, 'a');
	while (node_min->pos != 0)
	{
		if (node_min->pos <= size / 2)
			ra(stacks);
		else
			rra(stacks);
		node_position(stacks, 'a');
	}
}

void	push_to_top_a(t_stacks *stacks, t_node *target, int stack_len)
{
	int	above_median;

	if (target->pos <= stack_len / 2)
		above_median = 1;
	else
		above_median = 0;
	while (stacks->head_a != target)
	{
		if (above_median)
			ra(stacks);
		else
			rra(stacks);
	}
}
