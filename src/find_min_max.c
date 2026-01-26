/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:36:13 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/01/26 13:57:46 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	find_min_max(t_stacks *stacks)//verifier si il n'y pas de appel en trop
{
	stacks->min_a = find_min(stacks->head_a);
	stacks->max_a = find_max(stacks->head_a);
	stacks->min_b = find_min(stacks->head_b);
	stacks->max_b = find_max(stacks->head_b);
}

t_node	*find_min(t_node *head)
{
	t_node	*new_min;
	t_node	*nbr;

	new_min = head;
	nbr = head->next;
	while (nbr->next)
	{
		if (new_min->nbr > nbr->nbr)
			new_min = nbr;
		nbr = nbr->next;
	}
	return (new_min);
}

t_node	*find_max(t_node *head)
{
	t_node	*new_max;
	t_node	*nbr;

	new_max = head;
	nbr = head->next;
	while (nbr->next)
	{
		if (new_max->nbr < nbr->nbr)
			new_max = nbr;
		nbr = nbr->next;
	}
	return (new_max);
}
