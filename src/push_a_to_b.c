/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 17:14:57 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/01/29 16:30:50 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_a_to_b(t_stacks *stacks)
{
	pb(stacks);
	pb(stacks);
	node_position(stacks, 'a');
	node_position(stacks, 'b');
	ft_printf("1 et 2 push dans b car stacksize est plus grand que 4\n");
	while (stack_size(stacks->head_a) != 3)
	{
		node_position(stacks, 'a');
		node_position(stacks, 'b');
		find_min_max(stacks);
		find_all_target(stacks);
		stacks->b_len = stack_size(stacks->head_b);
		push_to_top_b(stacks, stacks->head_a->target, stacks->b_len);
		pb(stacks);
	}
	ft_printf("stack == 3\n");
	sort_three(stacks);
	ft_printf("sort_three\n");
}


void	push_to_top_b(t_stacks *stacks, t_node *target, int stack_len)
{
	int	above_median;

	if (target->pos <= stack_len / 2)
		above_median = 1;
	else
		above_median = 0;

	while (stacks->head_b != target)
	{
		if (above_median)
			rb(stacks);
		else
			rrb(stacks);
	}
}

int	find_median(int stack_size)
{
	int	median;

	median = stack_size / 2;
	return (median);
}
