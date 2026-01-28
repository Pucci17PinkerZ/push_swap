/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:23:56 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/01/28 14:19:55 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rb(t_stacks *stacks)
{
	t_node	*new_top;
	t_node	*old_end;
	
	old_end = last_node(stacks->head_b);
	new_top = stacks->head_b->next;
	new_top->prev = NULL;
	stacks->head_b->next = NULL;
	old_end->next = stacks->head_b;
	stacks->head_b->prev = old_end;
	stacks->head_b = new_top;
	ft_printf("rb\n");
	return ;
}
