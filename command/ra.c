/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:23:53 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/01/22 20:02:40 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_node *a)
{
	t_node	*new_top;
	t_node	*old_end;
	
	old_end = last_node(a);
	new_top = a->next;
	new_top->prev = NULL;
	a->next = NULL;
	old_end->next = a;
	a->prev = old_end;
	a = new_top;
	ft_printf("ra\n");
	return ;
}
