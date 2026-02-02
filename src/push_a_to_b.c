/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 17:14:57 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/02/01 23:12:30 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_a_to_b(t_stacks *stacks)
{
	pb(stacks);
	pb(stacks);
	node_position(stacks, 'a');
	node_position(stacks, 'b');
	while (stack_size(stacks->head_a) != 3)
	{
		node_position(stacks, 'a');
		node_position(stacks, 'b');
		find_min_max(stacks);
		find_all_target(stacks);
		all_push_cost(stacks);
		stacks->cheapest = find_cheapest(stacks);
		push_top_or_bottom(stacks, stacks->cheapest);
		pb(stacks);
	}
	sort_three(stacks);
}

void	push_top_or_bottom(t_stacks *stacks, t_node *cheapest)
{
	t_node	*target;
	int		median_a;
	int		median_b;

	target = cheapest->target;
	median_a = find_median(stack_size(stacks->head_a));
	median_b = find_median(stack_size(stacks->head_b));
	if (cheapest->pos == 0 && target->pos == 0)
		return ;
	if (target->pos <= median_b && cheapest->pos <= median_a)
		do_push_top_top(stacks, cheapest, target);
	else if (target->pos > median_b && cheapest->pos > median_a)
		do_push_bottom_bottom(stacks, cheapest, target);
	else
		do_push_mixed(stacks, cheapest, target);
	return ;
}
