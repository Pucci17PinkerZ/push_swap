/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:24:03 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/01/29 15:17:29 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_stacks *stacks)
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
	ft_printf("rra\n");
}
