/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 10:57:06 by nfiora-d          #+#    #+#             */
/*   Updated: 2026/01/29 14:38:12 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// void	sort_three(t_stacks *stacks)
// {
// 	int	num1;
// 	int	num2;
// 	int	num3;

// 	num1 = stacks->head_a->nbr;
// 	num2 = stacks->head_a->next->nbr;
// 	num3 = stacks->head_a->next->next->nbr;
// 	if (num1 < num2 && num2 > num3 && num1 < num3)
// 		rra(stacks);
// 	else if (num1 > num2 && num2 > num3 && num1 > num3)
// 		ra(stacks);
// 	if (num1 > num2 && num2 < num3 && num1 > num3)
// 		sa(stacks);
// 	else if (num1 < num2 && num2 > num3 && num1 > num3)
// 		rra(stacks);
// 	else if (num1 > num2 && num2 < num3 && num1 > num3)
// 		ra(stacks);
// }


void	sort_three(t_stacks *stacks)
{
	t_node	*biggest_node;

	biggest_node = find_max(stacks, 'a');


	if (stacks->head_a == biggest_node)
		ra(stacks);
	else if (stacks->head_a->next == biggest_node)
		rra(stacks);


	if (stacks->head_a->nbr > stacks->head_a->next->nbr)
		sa(stacks);
}


int stack_size(t_node *node)
{
	int i = 0;

	while (node)
	{
		i++;
		node = node->next;
	}
	return (i);
}

int	check_stack_order(t_node *a)
{
	t_node	*node;
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
	//ici une fonction pour clear les nodes//atteint cette ligne
	return (1);
}


void	node_position(t_stacks *stacks, char letter)
{
	t_node	*tmp;
	int		i;
	
	i = 0;
	if (letter == 'a' && !stacks->head_a)
		return ;
	if (letter == 'b' && !stacks->head_b)
		return ;
	if (letter == 'a')
		tmp = stacks->head_a;
	else
		tmp = stacks->head_b;
	tmp->pos = i;
	tmp = tmp->next;
	while (tmp)
	{
		i++;
		tmp->pos = i;
		tmp = tmp->next;
	}
	return ;
}

void	show_stack(t_stacks *stacks)
{
	t_node *tmp;
	
	ft_printf("\nSTACKS A\n");
	if (!stacks->head_a)
	{
		ft_printf("Stack vide\n");
	}
	tmp = stacks->head_a;
	while (tmp)
	{
		ft_printf("node %d  / valeur %d\n", tmp->pos, tmp->nbr);
		tmp = tmp->next;
	}
	ft_printf("\nSTACKS B\n");
	if (!stacks->head_b)
	{
		ft_printf("Stack vide\n");
	}
	tmp = stacks->head_b;
	while (tmp)
	{
		ft_printf("node %d  / valeur %d\n", tmp->pos, tmp->nbr);
		tmp = tmp->next;
	}
	ft_printf("\n");
}
