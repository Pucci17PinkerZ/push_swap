/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:23:50 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/01/28 12:27:20 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// void	pb(t_node *b, t_node *a)
// {
// 	t_node	*new_top_b;
	
// 	b->next->prev = NULL;
// 	new_top_b = b->next;
// 	a->prev = b;
// 	b->next = a;
// 	a = b;
// 	b = new_top_b;
// 	ft_printf("pb\n");
// 	return ;
// }
void	pb(t_node *a ,t_node *b)
{
	t_node	*new_top;
	
	if (!b)
	{
		new_top = a;
		a = a->next;
		a->prev = NULL;
		a->next = NULL;
		b = new_top;
		return ;
	}
	b->prev = a;
	new_top = a->next;
	a->next = b;
	b = a;
	a = new_top;
	ft_printf("pb\n");
	return ;
}
