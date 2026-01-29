/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:24:11 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/01/29 15:03:01 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* sa.c                                               :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2026/01/15 17:24:11 by pucci17pink       #+#    #+#             */
/* Updated: 2026/01/29 11:58:20 by pucci17pink      ###   ########.fr       */
/* */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stacks *stacks)
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
	ft_printf("sa\n");
}

t_node	*find_node_c(t_node *a)
{
	t_node	*next;

	next = a->next;
	return (next->next);
}
