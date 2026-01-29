/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:23:59 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/01/29 15:17:20 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rr(t_stacks *stacks)
{
	ra_2(stacks);
	rb_2(stacks);
	ft_printf("rr\n");
	return ;
}
void	ra_2(t_stacks *stacks)
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
	node_position(stacks, 'a');
	return ;
}

void	rb_2(t_stacks *stacks)
{
	t_node	*new_top;
	t_node	*old_end;

	if (!stacks->head_b || !stacks->head_b->next)
		return ;

	old_end = last_node(stacks->head_b);
	new_top = stacks->head_b->next;
	
	new_top->prev = NULL;
	

	stacks->head_b->next = NULL;
	old_end->next = stacks->head_b;
	stacks->head_b->prev = old_end;
	stacks->head_b = new_top;
	node_position(stacks, 'b');
		return ;
}