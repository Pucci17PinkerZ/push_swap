/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 16:09:48 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/01/29 16:31:36 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	clean_exit(t_stacks *stacks)
{
	clean_a(stacks);
	stacks->head_a = NULL;
	clean_b(stacks);
	stacks->head_b = NULL;
}

void	clean_a(t_stacks *stacks)
{
	t_node	*current;
	t_node	*next_node;

	if (!stacks || !stacks->head_a)
		return ;

	current = stacks->head_a;
	while (current)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	stacks->head_a = NULL;
}

void	clean_b(t_stacks *stacks)
{
	t_node	*current;
	t_node	*next_node;

	if (!stacks || !stacks->head_b)
		return ;

	current = stacks->head_b;
	while (current)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	stacks->head_b = NULL;
}


void	free_tab(char **tab, int j)
{
	if (!tab || !tab[j])
		return ;
	while (tab[j])
		j++;
	while (j > 0)
		free(tab[--j]);
	free(tab);
}
