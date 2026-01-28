/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 17:15:01 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/01/28 17:24:42 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_b_to_a(t_stacks *stacks)
{

	while (stack_size(stacks->head_b) != 0)//vérifier la condition
	{
		node_position(stacks, 'a');
		node_position(stacks, 'b');
		show_stack(stacks);//to delete
		find_min_max(stacks);
		find_all_target_2(stacks);
		all_push_cost(stacks);
		stacks->cheapest = find_cheapest(stacks);
		push_top_or_bottom(stacks, stacks->cheapest, NULL);
		pa(stacks);
	}
	node_position(stacks, 'a');
	final_sort(stacks);
	return ;
}

void	final_sort(t_stacks *stacks)
{
	t_node	*node_on_top;
	int		median;

	node_on_top = find_min(stacks, 'a');
	while (node_on_top->pos != 0)
	{
		median = find_median(stack_size(stacks->head_a));
		if (node_on_top->pos <= median)
			ra(stacks);
		else
			rra(stacks);
	}
	return ;
}

void	push_top_or_bottom(t_stacks *stacks, t_node *cheapest, t_node *target)
{
	int	median_a_is;
	int	median_b_is;

	median_a_is = find_median(stacks->a_len);
	median_b_is = find_median(stacks->b_len);
	target = cheapest->target;//check if useless
	if (cheapest->pos == 0 && target->pos == 0)
		return ;
	if (target->pos <= median_a_is && cheapest->pos <= median_b_is)
		push_top_top(stacks, cheapest, target);
	else if (target->pos > median_a_is && cheapest->pos > median_b_is)
		push_bottom_bottom(stacks, cheapest, target);
	else if (target->pos > median_a_is && cheapest->pos <= median_b_is)
		push_bottom_top(stacks, cheapest, 'a', target);
	else
		push_bottom_top(stacks, cheapest, 'b', target);
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

void	do_push_top_top(t_node *bigger,
	t_node *smaller, char letter, t_stacks *stacks)
{
	int	i;

	i = 0;
	while (i < (bigger->pos - smaller->pos))
	{
		if (letter == 'a')
			ra(stacks);
		else
			rb(stacks);
		i++;
	}
	i = 0;
	while (i < smaller->pos)
	{
		rr(stacks);
		i++;
	}
	return ;
}

void	push_bottom_bottom(t_stacks *stacks,
		t_node *cheapest, t_node *target)
{
	t_node	*bigger;
	t_node	*smaller;

	target = cheapest->target;
	if (cheapest->pos >= target->pos)
	{
		bigger = cheapest;
		smaller = target;
		do_push_bottom_bottom_b(bigger, smaller, stacks);
	}
	else
	{
		bigger = target;
		smaller = cheapest;
		do_push_bottom_bottom_a(bigger, smaller, stacks);
	}
	return ;
}

void	do_push_bottom_bottom_a(t_node *bigger,
		t_node *smaller, t_stacks *stacks)
{
	int	i;

	i = 0;
	while (i < ((stacks->a_len - bigger->pos) - (stacks->a_len - smaller->pos)))
	{
		rra(stacks);
		i++;
	}
	i = -1;
	while (i < (stacks->a_len - smaller->pos))
	{
		rrr(stacks);
		i++;
	}
	return ;
}

void	do_push_bottom_bottom_b(t_node *bigger,
		t_node *smaller, t_stacks *stacks)
{
	int	i;

	i = 0;
	while (i < ((stacks->b_len - bigger->pos) - (stacks->b_len - smaller->pos)))
	{
		rrb(stacks);
		i++;
	}
	i = -1;
	while (i < (stacks->b_len - smaller->pos))
	{
		rrr(stacks);
		i++;
	}
	return ;
}

void	push_bottom_top(t_stacks *stacks, t_node *cheapest,
		char letter, t_node *target)
{
	t_node	*bigger;
	t_node	*smaller;

	if (letter == 'b')
	{
		bigger = target;
		smaller = cheapest;
		do_push_bottom_top(bigger, smaller, letter, stacks);
	}
	else
	{
		bigger = cheapest;
		smaller = target;
		do_push_bottom_top(bigger, smaller, letter, stacks);
	}
	return ;
}
void	do_push_bottom_top2(int index_1,
		int index_2, char letter, t_stacks *stacks)
{
	int	i;

	i = 0;
	while (i < index_1)
	{
		if (letter == 'a')
			rra(stacks);
		else
			rrb(stacks);
		i++;
	}
	i = 0;
	while (i < index_2)
	{
		if (letter == 'a')
			rb(stacks);
		else
			ra(stacks);
		i++;
	}
	return ;
}

void	do_push_bottom_top(t_node *bigger,
		t_node *smaller, char letter, t_stacks *stacks)
{

	int	index_1;
	int	index_2;

	if (letter == 'a')
	{
		index_1 = stacks->a_len - bigger->pos;
		index_2 = smaller->pos;
		do_push_bottom_top2(index_1, index_2, letter, stacks);
	}
	else
	{
		index_1 = stacks->b_len - smaller->pos;
		index_2 = bigger->pos;
		do_push_bottom_top2(index_1, index_2, letter, stacks);
	}
	return ;
}
