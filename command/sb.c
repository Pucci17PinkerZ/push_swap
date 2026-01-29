/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:24:14 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/01/29 15:14:53 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sb(t_stacks *stacks)
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
	ft_printf("sb\n");
}
