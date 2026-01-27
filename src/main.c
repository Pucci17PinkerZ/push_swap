/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 10:57:06 by nfiora-d          #+#    #+#             */
/*   Updated: 2026/01/27 19:05:34 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int ac, char **av)
{
	t_stacks	stacks;

	ft_bzero(&stacks, sizeof(t_stacks));
	if (ac < 2)
		return (1);//printf error here??
	if (check_input(av + 1, &stacks))
		return (ft_printf("Error\n"), 1);
	sort_node(&stacks);
	clean_exit(&stacks);
	return (0);
}

void	sort_node(t_stacks *stacks)
{

	if (check_stack_order(stacks->head_a))
		return ;
	while (check_stack_order(stacks->head_a))
	{
		push_a_to_b(stacks);
		push_b_to_a(stacks);
	}
	return ;
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
