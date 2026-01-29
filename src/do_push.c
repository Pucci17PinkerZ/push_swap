/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 17:14:57 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/01/29 16:30:50 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	do_push_top_top(t_stacks *stacks, t_node *cheapest, t_node *target)
{
	while (cheapest->pos > 0 && target->pos > 0)
		rr(stacks);
	while (cheapest->pos > 0)
		rb(stacks);
	while (target->pos > 0)
		ra(stacks);
}

void	do_push_bottom_bottom(t_stacks *stacks,
	t_node *cheapest, t_node *target)
{
	while (cheapest->pos != 0 && target->pos != 0)
		rrr(stacks);
	while (cheapest->pos != 0)
		rrb(stacks);
	while (target->pos != 0)
		rra(stacks);
}

void	do_push_mixed(t_stacks *stacks, t_node *cheapest, t_node *target)
{
	int	median_a;
	int	median_b;

	median_a = find_median(stack_size(stacks->head_a));
	median_b = find_median(stack_size(stacks->head_b));
	if (target->pos <= median_a)
		while (target->pos != 0)
			ra(stacks);
	else
		while (target->pos != 0)
			rra(stacks);
	if (cheapest->pos <= median_b)
		while (cheapest->pos != 0)
			rb(stacks);
	else
		while (cheapest->pos != 0)
			rrb(stacks);
}
