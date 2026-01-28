/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:23:46 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/01/28 14:38:38 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_stacks *stacks)
{
	t_node	*new_top_a;
	
	stacks->head_a->next->prev = NULL;
	new_top_a = stacks->head_a->next;
	stacks->head_b->prev = stacks->head_a;
	stacks->head_a->next = stacks->head_b;
	stacks->head_b = stacks->head_a;
	stacks->head_a = new_top_a;
	ft_printf("pa\n");
	return ;
}
