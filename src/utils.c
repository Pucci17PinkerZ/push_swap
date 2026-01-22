/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 10:57:06 by nfiora-d          #+#    #+#             */
/*   Updated: 2026/01/22 16:12:03 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"



void	sort_three(t_node *a) //pas certain des conditions ici
{
	int	num1;
	int	num2;
	int	num3;

	num1 = a->nbr;
	num2 = a->next->nbr;
	num3 = a->next->next->nbr;
	if (num1 < num2 && num2 > num3 && num1 < num3)
		rra(a);
	else if (num1 > num2 && num2 > num3 && num1 > num3)
		ra(a);
	if (num1 > num2 && num2 < num3 && num1 > num3)
		sa(a);
	else if (num1 < num2&& num2 > num3 && num1 > num3)
		rra(a);
	else if (num1 > num2&& num2 < num3 && num1 > num3)
		ra(a);
}

int	stack_size(t_node *node)
{
	t_node *next_node;
	int		i;
	
	i = 0;
	next_node = node->next;
	while(next_node->next)
	{
		next_node = next_node->next;
		i++;
	}
	return (i);
}

int		check_stack_order(t_node *a)
{
	t_node	*node
	int		num;
	int		i;
	
	i = 0;
	node = a;
	num = a->nbr;
	while (i++ < stack_size(a))
	{
		node = node->next;
		if (num > node->nbr)
			return (0);
		num = node->nbr;
	}
	//ici une fonction pour clear les nodes
	return (1);//atteint cette ligne
}

int	check_doubles()
{
	
}

void	node_position(t_node *a)
{
	t_node	*next_node;
	t_node	*tmp;

	tmp = a;
	tmp->pos = 1;
	while(tmp->next)
	{
		next_node = tmp->next;
		next_node->pos++;
		tmp = next_node;
	}
	return ;
}
