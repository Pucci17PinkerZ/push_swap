/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 17:15:01 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/01/25 14:14:50 by pucci17pink      ###   ########.fr       */
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
		push_top_or_bottom(stacks, stacks->cheapest, NULL);
		pa(stacks->head_a, stacks->head_b);
	}
}

void	push_top_or_bottom(t_stacks *stacks, t_node *cheapest, t_node *target)
{
	int	*median_a_is;
	int	*median_b_is;
	
	median_a_is = find_median(stacks->a_len);
	median_b_is = find_median(stacks->b_len);
	target = cheapest->target;//check if useless
	if (cheapest->pos <= median_a_is && target->pos <= median_b_is)
		push_top_top(stacks, cheapest, target);
	else if (cheapest->pos > median_a_is && target->pos > median_b_is)
		push_bottom_bottom(stacks, cheapest, target);
	else if (cheapest->pos <= median_a_is && target->pos > median_b_is)
		push_bottom_top();
	else
		push_top_bottom();
}

void	push_top_top(t_stacks *stacks, t_node *cheapest, t_node *target)
{
	t_node	*bigger;
	t_node	*smaller;

	if (cheapest->pos >= target->pos)
	{
		bigger = cheapest;
		smaller = target;
		do_push_top_top(bigger, smaller, 'b', stacks);
	}
	else
	{
		bigger = target;
		smaller = cheapest;
		do_push_top_top(bigger, smaller, 'a', stacks);
	}
	return ;
}

void	do_push_top_top(t_node *bigger, t_node *smaller, char letter, t_stacks *stacks)
{
	int	i;

	i = 0;
	while (i < (bigger->pos - smaller->pos))
	{
		if (letter == 'a')
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

void	push_bottom_bottom(t_stacks *stacks, t_node *cheapest, t_node *target)
{
	t_node	*bigger;
	t_node	*smaller;

	target = cheapest->target;
	if (cheapest->pos >= target->pos)
	{
		bigger = cheapest;
		smaller = target;
		do_push_bottom_bottom(bigger, smaller, 'b', stacks);
	}
	else
	{
		bigger = target;
		smaller = cheapest;
		do_push_bottom_bottom(bigger, smaller, 'a', stacks);
	}
	return ;
}

void	do_push_bottom_bottom(t_node *bigger, t_node *smaller, char letter, t_stacks *stacks)
{
	int	i;

	i = 0;
	while (i < (bigger->pos - smaller->pos))
	{
		if (letter == 'a')
			rra(stacks->head_a);
		else
			rrb(stacks->head_b);
		i++;
	}
	i = -1;
	while (i < smaller->pos)
	{
		rrr(stacks->head_a, stacks->head_b);
		i++;
	}
	return ;
}

void	push_bottom_top()
{
	
}

void	push_top_bottom()
{
	
}
