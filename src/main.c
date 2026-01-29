/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 10:57:06 by nfiora-d          #+#    #+#             */
/*   Updated: 2026/01/29 16:31:08 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int ac, char **av)
{
	t_stacks	stacks;

	ft_bzero(&stacks, sizeof(t_stacks));
	if (ac < 2)
		return (1);
	if (check_input(av + 1, &stacks))
		return (ft_printf("Error\n"), 1);
	sort_node(&stacks);
	clean_exit(&stacks);
	return (0);
}

void	sort_node(t_stacks *stacks)
{
	int	size;

	size = stack_size(stacks->head_a);
	if (size <= 1)
		return ;
	if (size == 2)
	{
		if (stacks->head_a->nbr > stacks->head_a->next->nbr)
			sa(stacks);
		return ;
	}
	if (size == 3)
		sort_three(stacks);
	else if (size <= 5)
		sort_five(stacks);
	else
	{
		push_a_to_b(stacks);
		push_b_to_a(stacks);
	}
		
}

int	is_node_sorted(t_node *a)
{
	t_node	*curr;

	if (!a)
		return (0);
	curr = a;
	while (curr->next)
	{
		if (curr->nbr > curr->next->nbr)
			return (1);
		curr = curr->next;
	}
	return (0);
}
