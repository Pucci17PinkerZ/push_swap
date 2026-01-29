/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:23:50 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/01/29 11:58:25 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// void	pb(t_node *b, t_node *a)
// {
// 	t_node	*new_top_b;
	
// 	b->next->prev = NULL;
// 	new_top_b = b->next;
// 	a->prev = b;
// 	b->next = a;
// 	a = b;
// 	b = new_top_b;
// 	ft_printf("pb\n");
// 	return ;
// }
void	pb(t_stacks *stacks)
{
	t_node	*new_top;
	
	if (!stacks->head_b)
	{
		new_top = stacks->head_a;
		stacks->head_a = stacks->head_a->next;
		new_top->next = NULL;
		stacks->head_a->prev = NULL;
		stacks->head_b = new_top;
		return ;
	}
	stacks->head_b->prev = stacks->head_a;
	new_top = stacks->head_a->next;
	stacks->head_a->next = stacks->head_b;
	stacks->head_b = stacks->head_a;
	stacks->head_a = new_top;
	node_position(stacks, 'b');
	ft_printf("pb\n");
	return ;
}
