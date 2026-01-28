/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:24:03 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/01/28 18:09:39 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// void	rra(t_stacks *stacks)
// {
// 	t_node	*new_head;
// 	t_node	*new_end;

// 	new_head = last_node(stacks->head_a);
// 	show_stack(stacks);
// 	new_end = new_head->prev;//ici new_head->prev n'existe pas
// 	new_end->next = NULL;
// 	new_head->prev = NULL;
// 	stacks->head_a->prev = new_head;
// 	new_head->next = stacks->head_a;
// 	stacks->head_a = new_head;
// 	ft_printf("rra\n");
// 	return ;
// }

void	rra(t_stacks *stacks)
{
	t_node	*head;
	t_node	*end;

	end = last_node(stacks->head_a);
	head = stacks->head_a;
	show_stack(stacks);
	end->next = head;
	end->prev->next = NULL;
	end->prev = NULL;
	head->prev = end;
	stacks->head_a = end;
	ft_printf("rra\n");
	return ;
}