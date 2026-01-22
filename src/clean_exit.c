/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 16:09:48 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/01/22 16:12:12 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	clean_exit(t_stacks *stacks)
{
	clean_a(stacks->head_a);
	clean_b(stacks->head_b);
}

void	clean_a(t_node *a)
{
	t_node *tmp;
	
	if (!a)
		return ;
	tmp = a->next;
	while (tmp->next)
	{
		free(a);
		a = tmp;
		tmp = a->next;
	}
	return ;
}

void	clean_b(t_node *b)
{
	t_node *tmp;
	
	if (!b)
		return ;
	tmp = b->next;
	while (tmp->next)
	{
		free(b);
		b = tmp;
		tmp = b->next;
	}
	return ;
}