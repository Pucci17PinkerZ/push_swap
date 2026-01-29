/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:53:22 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/01/29 14:53:48 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	bring_min_to_top(t_stacks *stacks)
{
	t_node	*min_node;
	int		size;

	// 1. On s'assure que les positions sont à jour
	node_position(stacks, 'a');
	
	// 2. On trouve le minimum
	min_node = find_min(stacks, 'a');
	size = stack_size(stacks->head_a);

	// 3. On choisit le chemin le plus court (ra ou rra)
	if (min_node->pos <= size / 2)
	{
		// Si dans la première moitié -> on monte avec ra
		while (stacks->head_a != min_node)
			ra(stacks);
	}
	else
	{
		// Si dans la deuxième moitié -> on descend avec rra
		while (stacks->head_a != min_node)
			rra(stacks);
	}
}

/*
** Fonction principale pour trier 4 ou 5 éléments.
*/
void	sort_five(t_stacks *stacks)
{
	// Tant qu'il reste plus de 3 éléments dans A (donc pour 5 et 4)
	while (stack_size(stacks->head_a) > 3)
	{
		bring_min_to_top(stacks); // On met le min en haut
		pb(stacks);               // On le pousse vers B
	}
	
	// Maintenant qu'il reste exactement 3 éléments dans A, on les trie
	sort_three(stacks);

	// On ramène les éléments de B vers A.
	// Comme on a poussé les plus petits en premier, B est trié à l'envers.
	// En faisant 'pa', ils reviennent dans le bon ordre au sommet de A.
	while (stacks->head_b)
		pa(stacks);
}