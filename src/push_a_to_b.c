/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 17:14:57 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/01/22 15:56:51 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_a_to_b(t_stacks *stacks)
{
	pa(a, b);
	pa(a, b);
	node_position(a);
	node_position(b);
	while (stack_size(a) != 3)
	{
		find_min_max(stack);
		find_all_target(a, b);
		push_cost();//not done too
		find_cheapest();//not done
		do_push();//not done
	}
	sort_three();
}

void	find_all_target(t_game *a, t_game *b)
{
	t_node	*next_node;
	
	while (a->next)
	{
		a->target = find_target_b(b);
	}
}

t_node	*find_target_b(t_node *b, int nbr)
{
	t_node	*tmp_target;
	t_node	*target;

	tmp_target = b;
	while(tmp_target->next)
	{
		if (nbr > tmp_target->nbr)
		{
			if (!target)
				target = tmp_target;
			else if (tmp_target->nbr > target->nbr)
				
				target = tmp_target;
		}
		//changement de struct
	}
	if ()
}