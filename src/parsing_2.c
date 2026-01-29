/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 10:57:06 by nfiora-d          #+#    #+#             */
/*   Updated: 2026/01/29 16:31:04 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	set_node(t_stacks *stacks, int nbr)
{
	t_node	*end_node;
	t_node	*new_node;

	if (stacks->head_a == NULL)
	{
		if (set_first_node(stacks))
			return (1);
	}
	else
	{
		end_node = last_node(stacks->head_a);
		new_node = malloc(sizeof(t_node));
		if (!new_node)
			return (1);
		new_node->nbr = nbr;
		new_node->pos = end_node->pos + 1;
		new_node->cost = 0;
		new_node->target = NULL;
		new_node->next = NULL;
		new_node->prev = end_node;
		end_node->next = new_node;
	}
	return (0);
}

t_node	*last_node(t_node *a)
{
	t_node	*final_node;
	t_node	*tmp;

	if (!a)
		return (NULL);
	tmp = a;
	while (tmp)
	{
		final_node = tmp;
		tmp = tmp->next;
	}
	return (final_node);
}

int	set_first_node(t_stacks *stacks)
{
	stacks->head_a = malloc(sizeof(t_node));
	if (!stacks->head_a)
		return (1);
	stacks->head_a->nbr = nbr;
	stacks->head_a->pos = 0;
	stacks->head_a->next = NULL;
	stacks->head_a->prev = NULL;
	return (0);
}
