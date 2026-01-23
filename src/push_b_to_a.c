/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 17:15:01 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/01/23 17:12:07 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

push_b_to_a(t_stacks *stacks)
{
	node_position(a)
	node_position(b);
	while (stack_size(a) != 0)//vérifier la condition
	{
		find_min_max(stacks);
		find_all_target_2(stacks);
		all_push_cost(stacks);
		stacks->cheapest = find_cheapest(stacks);
		push_to_top(stacks, stacks->cheapest, NULL);
		pa(stacks->head_a, stacks->head_b);
	}
}

t_node	*find_cheapest(t_stacks *stacks)
{
	t_node	*cheapest;
	t_node	*next_node
	
	cheapest = stacks->head_b;
	if (stacks->head_b->next == NULL)
		return (cheapest);
	next_node = cheapest->next;
	while (next_node->next)
	{
		if (cheapest->cost == 0)
			return (cheapest);
		if (cheapest->cost > next_node->cost)
			cheapest = next_node;
		next_node = next_node->next;
	}
	return (cheapest);
}

void	do_push(t_node *bigger, t_node *smaller, char letter, t_stacks *stacks)
{
	int	i;

	i = 0;
	while (i < (bigger->pos - smaller->pos))
	{
		if (letter == a)
			ra(stacks->head_a);
		else
			rb(stacks->head_b);
		i++;
	}
	i = 0;
	while (i < smaller->pos)
	{
		rr(stacks->head_a, stacks->head_b);
		i++;
	}
	return ;
}


void	push_top_top(t_stacks *stacks, t_node *cheapest, t_node *target)
{
	t_node	*bigger;
	t_node	*smaller;

	target = cheapest->target;
	if (cheapest->pos >= target->pos)
	{
		bigger = cheapest;
		smaller = target;
		do_push(bigger, smaller, 'b', stacks);
	}
	else
	{
		bigger = target;
		smaller = cheapest;
		do_push(bigger, smaller, 'a', stacks);
	}
	return ;
}

void	push_bottom_bottom()

void	push_bottom_top()

void	push_top_bottom()

void	push_up_or_down();
{
	int	median;

	median = find_median();
}