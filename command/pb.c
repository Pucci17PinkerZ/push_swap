/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:23:50 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/02/02 05:04:52 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
		ft_printf("pb\n");
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

// void	pb(t_stacks *stacks)
// {
// 	t_node	*node_to_push;

// 	// 1. Si A est vide, on ne fait rien
// 	if (!stacks->head_a)
// 		return ;

// 	// 2. On isole le noeud à bouger
// 	node_to_push = stacks->head_a;
// 	stacks->head_a = stacks->head_a->next;

// 	if (stacks->head_a)
// 		stacks->head_a->prev = NULL;

// 	// 3. On ajoute sur B
// 	node_to_push->next = stacks->head_b;
// 	if (stacks->head_b)
// 		stacks->head_b->prev = node_to_push;

// 	stacks->head_b = node_to_push;
// 	stacks->head_b->prev = NULL;

// 	node_position(stacks, 'b');
// 	node_position(stacks, 'a');
// 	ft_printf("pb\n");
// }

