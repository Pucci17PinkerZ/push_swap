/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:36:13 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/01/29 11:52:00 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	find_min_max(t_stacks *stacks)//verifier si il n'y pas de appel en trop
{
	stacks->min_a = find_min(stacks, 'a');
	stacks->max_a = find_max(stacks, 'a');
	stacks->min_b = find_min(stacks, 'b');
	stacks->max_b = find_max(stacks, 'b');
}

t_node	*find_min(t_stacks *stacks, char letter)
{
	t_node	*new_min;
	t_node	*nbr;
	
	if (letter == 'b' && !stacks->head_b)
		return (NULL);
	else if (letter == 'a')
		new_min = stacks->head_a;
	else
	{
		new_min = stacks->head_b;
		if (!new_min->next)
			return (new_min);
	}
	nbr = new_min->next;
	while (nbr)
	{
		if (new_min->nbr > nbr->nbr)
			new_min = nbr;
		nbr = nbr->next;
	}
	return (new_min);
}

t_node	*find_max(t_stacks *stacks, char letter)
{
	t_node	*new_max;
	t_node	*nbr;

	if (letter == 'a')
		new_max = stacks->head_a;
	else
	{
		new_max = stacks->head_b;
		if (!new_max->next)
			return (new_max);
	}
	nbr = new_max->next;
	while (nbr)
	{
		if (new_max->nbr < nbr->nbr)
			new_max = nbr;
		nbr = nbr->next;
	}
	return (new_max);
}
