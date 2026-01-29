/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:36:13 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/01/29 16:29:59 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	find_min_max(t_stacks *stacks)
{
	stacks->min_a = find_min(stacks, 'a');
	stacks->max_a = find_max(stacks, 'a');
	stacks->min_b = find_min(stacks, 'b');
	stacks->max_b = find_max(stacks, 'b');
}

t_node	*find_min(t_stacks *stacks, char letter)
{
	t_node	*min;
	t_node	*nbr;

	if (letter == 'a')
		min = stacks->head_a;
	else
		min = stacks->head_b;
	if (!min)
		return (NULL);
	nbr = min->next;
	while (nbr)
	{
		if (nbr->nbr < min->nbr)
			min = nbr;
		nbr = nbr->next;
	}
	return (min);
}

t_node	*find_max(t_stacks *stacks, char letter)
{
	t_node	*max;
	t_node	*nbr;

	if (letter == 'a')
		max = stacks->head_a;
	else
		max = stacks->head_b;
	if (!max)
		return (NULL);
	nbr = max->next;
	while (nbr)
	{
		if (nbr->nbr > max->nbr)
			max = nbr;
		nbr = nbr->next;
	}
	return (max);
}
