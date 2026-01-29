/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:23:46 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/01/29 11:58:10 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_stacks *stacks)
{
	t_node	*new_top;

	stacks->head_a->prev = stacks->head_b;
	new_top = stacks->head_b->next;
	stacks->head_b->next = stacks->head_a;
	stacks->head_a = stacks->head_b;
	stacks->head_b = new_top;
	node_position(stacks, 'a');
	ft_printf("pa\n");
	return ;
}
