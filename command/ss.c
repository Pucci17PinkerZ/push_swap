/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:24:17 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/01/29 15:21:48 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ss(t_stacks *stacks)
{
	sa_2(stacks);
	sb_2(stacks);
	ft_printf("ss\n");
	return ;
}

void	sa_2(t_stacks *stacks)
{
	t_node	*b;
	t_node	*c;

	if (!stacks->head_a || !stacks->head_a->next)
		return ;
	c = find_node_c(stacks->head_a);
	b = stacks->head_a->next;
	stacks->head_a->prev = b;
	if (c)
		c->prev = stacks->head_a;
	b->prev = NULL;
	b->next = stacks->head_a;
	stacks->head_a->next = c;
	stacks->head_a = b;
	node_position(stacks, 'a');
}

void	sb_2(t_stacks *stacks)
{
	t_node	*a;
	t_node	*c;

	if (!stacks->head_b || !stacks->head_b->next)
		return ;
	c = find_node_c(stacks->head_b);
	a = stacks->head_b->next;
	stacks->head_b->prev = a;
	if (c)
		c->prev = stacks->head_b;
	a->prev = NULL;
	a->next = stacks->head_b;
	stacks->head_b->next = c;
	stacks->head_b = a;
	node_position(stacks, 'b');
}
