/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:24:08 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/01/29 15:21:34 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rrr(t_stacks *stacks)
{
	rra_2(stacks);
	rrb_2(stacks);
	ft_printf("rrr\n");
	return ;
}

void	rra_2(t_stacks *stacks)
{
	t_node	*head;
	t_node	*end;

	if (!stacks->head_a || !stacks->head_a->next)
		return ;
	end = last_node(stacks->head_a);
	head = stacks->head_a;
	end->prev->next = NULL;
	end->next = head;
	head->prev = end;
	stacks->head_a = end;
	node_position(stacks, 'a');
}

void	rrb_2(t_stacks *stacks)
{
	t_node	*head;
	t_node	*end;

	if (!stacks->head_b || !stacks->head_b->next)
		return ;
	end = last_node(stacks->head_b);
	head = stacks->head_b;
	end->prev->next = NULL;
	end->next = head;
	head->prev = end;
	stacks->head_b = end;
	node_position(stacks, 'b');
}
