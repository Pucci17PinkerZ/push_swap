/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 17:14:57 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/01/21 18:02:25 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_a_to_b(t_game *a, t_game *b)
{
	pa(a, b);
	pa(a, b);
	node_position(a);
	node_position(b);
	while (stack_size(a) != 3)
	{
		find_all_target();
	}
}

void	find_all_target(t_game *a, t_game *b)
{
	t_node	*next_node;
	
	while (a->next)
	{
		a->target = find_target_b(b);
	}
}

t_node	*find_target_b(t_node *b)
{
	t_node	*tmp_target;
	t_node	*target;

	while(b->next)
	{
		
	}
}