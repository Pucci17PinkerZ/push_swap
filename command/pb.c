/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:23:50 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/01/22 20:02:35 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pb(t_node *b, t_node *a)
{
	t_node	*new_top_b;
	
	b->next->prev = NULL;
	new_top_b = b->next;
	a->prev = b;
	b->next = a;
	a = b;
	b = new_top_b;
	ft_printf("pb\n");
	return ;
}
