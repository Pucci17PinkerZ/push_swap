/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 16:09:48 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/01/26 15:09:20 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	clean_exit(t_stacks *stacks)
{
	clean_a(stacks->head_a);
	clean_b(stacks->head_b);
}

void	clean_a(t_node *a)
{
	t_node	*tmp;

	if (!a || a == NULL)
		return ;
	tmp = a;
	while (tmp)
	{
		free(a);
		a = tmp;
		tmp = a->next;
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
	if (!tab || !tab[j])
		return ;
	while (tab[j])
		j++;
	while (j > 0)
		free(tab[--j]);
	free(tab);
}
