/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:23:46 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/01/16 22:32:27 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_node *a, t_node *b)
{
	t_node	*new_top_a;
	
	a->next->prev = NULL;
	new_top_a = a->next;
	b->prev = a;
	a->next = b;
	*b = a;
	*a = new_top_a;
}
}
}
