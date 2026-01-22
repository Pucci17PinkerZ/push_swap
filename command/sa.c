/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:24:11 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/01/22 12:49:28 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_node *a)
{
	t_node	*b;
	t_node	*c;

	c = find_node_c(a);
	b = a->next;
	a->prev = a->next;
	c->prev = a;
	b->prev = NULL;
	b->next = a;
	a->next = c;
	a = b;
	ft_printf("sa");
	return ;
}

t_node	*find_node_c(t_node *a)
{
	t_node	*next;

	next = a->next;
	return (next->next);
}
