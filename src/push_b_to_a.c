/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 17:15:01 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/01/29 16:27:51 by pucci17pink      ###   ########.fr       */
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


void	do_push_bottom_bottom(t_stacks *stacks, t_node *cheapest, t_node *target)
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
	int median_a;
	int median_b;

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

	if (target->pos <= median_a && cheapest->pos <= median_b)
		do_push_top_top(stacks, cheapest, target);
	else if (target->pos > median_a && cheapest->pos > median_b)
		do_push_bottom_bottom(stacks, cheapest, target);
	
	else
		do_push_mixed(stacks, cheapest, target);
}



void	push_b_to_a(t_stacks *stacks)
{

	ft_printf("DEBUG: Entree push_b_to_a. Taille B = %d\n", stack_size(stacks->head_b));

	while (stack_size(stacks->head_b) != 0)
	{
		node_position(stacks, 'a');
		node_position(stacks, 'b');
		find_min_max(stacks); 

		find_all_target_2(stacks);
		all_push_cost(stacks);
		stacks->cheapest = find_cheapest(stacks);
		
		if (!stacks->cheapest) 
			ft_printf("DEBUG: Cheapest est NULL !\n");

		push_top_or_bottom(stacks, stacks->cheapest);
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
