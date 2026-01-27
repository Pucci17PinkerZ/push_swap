/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 16:09:48 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/01/27 18:15:50 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	clean_exit(t_stacks *stacks)
{
	clean_a(stacks);
	stacks->head_a = NULL;
	clean_b(stacks->head_b);
	stacks->head_b = NULL;
}

void	clean_a(t_stacks *stacks)
{
	t_node	*tmp;

	if (!stacks->head_a || stacks->head_a == NULL)
		return ;

	tmp = stacks->head_a;
	while (tmp)
	{
		tmp = tmp->next;
		free(stacks->head_a);
		stacks->head_a = tmp;
	}
	return ;
}

void	clean_b(t_node *b)
{
	t_node	*tmp;

	if (!b || b == NULL)
		return ;
	tmp = b;
	while (tmp)
	{
		free(b);
		b = tmp;
		tmp = b->next;
	}
	return ;
}

void	free_tab(char **tab, int j)
{
	printf("char tab vaut %p\n", tab);
	if (!tab || !tab[j])
		return ;
	while (tab[j])
		j++;
	while (j > 0)
		free(tab[--j]);
	free(tab);
}
