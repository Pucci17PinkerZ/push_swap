/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:24:05 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/01/28 14:21:23 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rrb(t_stacks *stacks)
{
	t_node	*end;
	t_node	*new_end;

	end = last_node(stacks->head_b);
	new_end = end->prev;
	new_end->next = NULL;
	end->prev = NULL;
	stacks->head_b->prev = end;
	end->next = stacks->head_b;
	stacks->head_b = end;
	ft_printf("rrb\n");
	return ;
}
