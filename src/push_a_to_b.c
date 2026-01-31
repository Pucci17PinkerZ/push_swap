/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 17:14:57 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/01/31 02:02:15 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// void	push_a_to_b(t_stacks *stacks)
// {
// 	pb(stacks);
// 	pb(stacks);
// 	node_position(stacks, 'a');
// 	node_position(stacks, 'b');
// 	while (stack_size(stacks->head_a) != 3)
// 	{
// 		node_position(stacks, 'a');
// 		node_position(stacks, 'b');
// 		find_min_max(stacks);
// 		find_all_target(stacks);
// 		stacks->b_len = stack_size(stacks->head_b);
// 		push_to_top_b(stacks, stacks->head_a->target, stacks->b_len);
// 		pb(stacks);
// 	}
// 	sort_three(stacks);
// }




// void	push_to_top_b(t_stacks *stacks, t_node *target, int stack_len)
// {
// 	int	above_median;

// 	if (target->pos <= stack_len / 2)
// 		above_median = 1;
// 	else
// 		above_median = 0;
// 	while (stacks->head_b != target)
// 	{
// 		if (above_median)
// 			rb(stacks);
// 		else
// 			rrb(stacks);
// 	}
// }

int	find_median(int stack_size)
{
	int	median;

	median = stack_size / 2;
	return (median);
}












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
		find_min_max(stacks);//on trouve le min / max de chaque stack
		find_all_target(stacks);//trouver toutes les target dans b
		all_push_cost(stacks);//calculer le cost de chaque target
		stacks->cheapest = find_cheapest(stacks);//choisir le moins cher
		push_top_or_bottom(stacks, stacks->cheapest);// push les deux au top de maniere ecolo
		pb(stacks);//une fois le deux au top on push et go again
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




void	do_push_top_top(t_stacks *stacks, t_node *cheapest, t_node *target)
{
	while (cheapest->pos > 0 && target->pos > 0)
		rr(stacks);
	while (cheapest->pos > 0)
		ra(stacks);
	while (target->pos > 0)
		rb(stacks);
}


void	do_push_bottom_bottom(t_stacks *stacks,
	t_node *cheapest, t_node *target)
{
	while (cheapest->pos != 0 && target->pos != 0)
		rrr(stacks);
	while (cheapest->pos != 0)
		rra(stacks);
	while (target->pos != 0)
		rrb(stacks);
}

void	do_push_mixed(t_stacks *stacks, t_node *cheapest, t_node *target)
{
	int	median_a;
	int	median_b;

	median_a = find_median(stack_size(stacks->head_a));
	median_b = find_median(stack_size(stacks->head_b));
	if (target->pos <= median_b)
		while (target->pos != 0)
			rb(stacks);
	else
		while (target->pos != 0)
			rrb(stacks);
	if (cheapest->pos <= median_a)
		while (cheapest->pos != 0)
			ra(stacks);
	else
		while (cheapest->pos != 0)
			rra(stacks);
}





void	find_all_target(t_stacks *stacks)
{
	t_node	*curr;

	curr = stacks->head_a;
	while (curr)
	{
		curr->target = find_target_b(stacks->head_b, curr->nbr, stacks->max_b);
		curr = curr->next;
	}
}


t_node	*find_target_b(t_node *b, int nbr, t_node *max_b)
{
	t_node	*actual_node;
	t_node	*target;

	actual_node = b;
	target = NULL;
	while (actual_node)
	{
		if (nbr > actual_node->nbr)
		{
			if (!target || actual_node->nbr > target->nbr)
				target = actual_node;
		}
		actual_node = actual_node->next;
	}
	if (!target)
		target = max_b;
	return (target);
}

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







































