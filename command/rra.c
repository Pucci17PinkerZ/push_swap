/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:24:03 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/01/28 14:20:47 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_stacks *stacks)
{
	t_node	*end;
	t_node	*new_end;

	end = last_node(stacks->head_a);
	new_end = end->prev;
	new_end->next = NULL;
	end->prev = NULL;
	stacks->head_a->prev = end;
	end->next = stacks->head_a;
	stacks->head_a = end;
	ft_printf("rra\n");
	return ;
}
