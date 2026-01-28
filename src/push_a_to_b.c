/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 17:14:57 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/01/28 15:54:14 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_a_to_b(t_stacks *stacks)
{
	pb(stacks);
	pb(stacks);
	show_stack(stacks);//to delete
	node_position(stacks, a);
	node_position(stacks, b);
	while (stack_size(stacks->head_a) != 3)
	{
		node_position(stacks, a);
		node_position(stacks, b);
		show_stack(stacks);//to delete
		find_min_max(stacks);
		find_all_target(stacks);
		stacks->b_len = stack_size(stacks->head_b);

		return ;
		push_to_top_b(stacks, stacks->head_a->target, stacks->b_len);
		pb(stacks);
	}
	sort_three(stacks);
}


void	push_to_top_b(t_stacks *stacks, t_node *target, int stack_size)
{
	int	median;

	while (target->pos != 0)
	{
		median = find_median(stack_size);
		if (target->pos <= median)
			rb(stacks);
		else
			rrb(stacks);
	}
	return ;
}

int	find_median(int stack_size)
{
	int	median;

	median = stack_size / 2;
	return (median);
}
