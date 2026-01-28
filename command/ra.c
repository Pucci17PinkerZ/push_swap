/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:23:53 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/01/28 14:18:49 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_stacks *stacks)
{
	t_node	*new_top;
	t_node	*old_end;
	
	old_end = last_node(stacks->head_a);
	new_top = stacks->head_a->next;
	new_top->prev = NULL;
	stacks->head_a->next = NULL;
	old_end->next = stacks->head_a;
	stacks->head_a->prev = old_end;
	stacks->head_a = new_top;
	ft_printf("ra\n");
	return ;
}
