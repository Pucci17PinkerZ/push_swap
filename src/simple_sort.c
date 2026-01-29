/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:53:22 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/01/29 16:11:46 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	bring_min_to_top(t_stacks *stacks)
{
	t_node	*min_node;
	int		size;

	node_position(stacks, 'a');
	min_node = find_min(stacks, 'a');
	size = stack_size(stacks->head_a);
	if (min_node->pos <= size / 2)
	{
		while (stacks->head_a != min_node)
			ra(stacks);
	}
	else
	{
		while (stacks->head_a != min_node)
			rra(stacks);
	}
}

void	sort_five(t_stacks *stacks)
{
	while (stack_size(stacks->head_a) > 3)
	{
		bring_min_to_top(stacks);
		pb(stacks);
	}
	sort_three(stacks);
	while (stacks->head_b)
		pa(stacks);
}
