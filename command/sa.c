/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:24:11 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/01/28 14:22:08 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stacks *stacks)
{
	t_node	*b;
	t_node	*c;

	c = find_node_c(stacks->head_a);
	b = stacks->head_a->next;
	stacks->head_a->prev = stacks->head_a->next;
	c->prev = stacks->head_a;
	b->prev = NULL;
	b->next = stacks->head_a;
	stacks->head_a->next = c;
	stacks->head_a = b;
	ft_printf("sa\n");
	return ;
}

t_node	*find_node_c(t_node *a)
{
	t_node	*next;

	next = a->next;
	return (next->next);
}
