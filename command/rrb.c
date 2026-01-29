/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:24:05 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/01/29 11:58:50 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// void	rrb(t_stacks *stacks)
// {
// 	t_node	*end;
// 	t_node	*new_end;

// 	end = last_node(stacks->head_b);
// 	new_end = end->prev;
// 	new_end->next = NULL;
// 	end->prev = NULL;
// 	stacks->head_b->prev = end;
// 	end->next = stacks->head_b;
// 	stacks->head_b = end;
// 	ft_printf("rrb\n");
// 	return ;
// }
void	rrb(t_stacks *stacks)
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
	ft_printf("rrb\n");
}