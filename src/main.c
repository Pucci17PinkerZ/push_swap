/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 10:57:06 by nfiora-d          #+#    #+#             */
/*   Updated: 2026/01/25 19:13:39 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int ac, char **av)
{
	t_node		a;
	t_node		b;
	t_stacks	stacks;

	stacks.head_a = &a;
	stacks.head_b = &b;
	if (check_input(ac, av, &stacks.a))
		return (clean_exit(&stacks), 1);
	if (check_doubles(&stacks.a))
		return (clean_exit(&stacks), 1);
	if (sort_node(&stacks))
		return (clean_exit(&stacks) 1);
	return (0);
}

int	sort_node(t_stacks * stacks)
{
	if (check_stack_order(stacks->head_a))//checker si c'est déjà dans l'ordre
		return ();
	while (check_stack_order(stacks->head_a))
	{
		push_a_to_b(stacks);
		push_b_to_a(stacks);
	}
}

int	is_node_sorted(t_node *a)
{
	t_node	*tmp;
	t_node	*big;
	t_node	*low;

	low = a;
	big = low->next;
	while (big->next)
	{
		if (low->nbr < big->nbr)
		{
			tmp = big;
			low = big;
			big = tmp->next;
		}
		else
			return (1);
	}
	return (0);
}
