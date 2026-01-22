/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:24:03 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/01/22 12:48:55 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_node *a)
{
	t_node	*end;
	t_node	*new_end;

	end = last_node(a);
	new_end = end->prev;
	new_end->next = NULL;
	end->prev = NULL;
	a->prev = end;
	end->next = a;
	a = end;
	ft_printf("rra");
	return ;
}
