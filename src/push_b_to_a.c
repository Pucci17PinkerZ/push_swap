/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 17:15:01 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/01/29 12:24:22 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


void	do_push_top_top(t_stacks *stacks, t_node *cheapest, t_node *target)
{
	while (cheapest->pos > 0 && target->pos > 0)
		rr(stacks);
	while (cheapest->pos > 0)
		rb(stacks);
	while (target->pos > 0)
		ra(stacks);
}


void	do_push_bottom_bottom(t_stacks *stacks, t_node *cheapest, t_node *target)
{
	while (cheapest->pos != 0 && target->pos != 0)
		rrr(stacks);
	while (cheapest->pos != 0)
		rrb(stacks);
	while (target->pos != 0)
		rra(stacks);
}

void	do_push_mixed(t_stacks *stacks, t_node *cheapest, t_node *target)
{
	int median_a;
	int median_b;

	median_a = find_median(stack_size(stacks->head_a));
	median_b = find_median(stack_size(stacks->head_b));
	if (target->pos <= median_a)
		while (target->pos != 0)
			ra(stacks);
	else
		while (target->pos != 0)
			rra(stacks);
	if (cheapest->pos <= median_b)
		while (cheapest->pos != 0)
			rb(stacks);
	else
		while (cheapest->pos != 0)
			rrb(stacks);
}

void	push_top_or_bottom(t_stacks *stacks, t_node *cheapest)
{
	t_node	*target;
	int		median_a;
	int		median_b;

	target = cheapest->target;
	median_a = find_median(stack_size(stacks->head_a));
	median_b = find_median(stack_size(stacks->head_b));

	if (cheapest->pos == 0 && target->pos == 0)
		return ;

	if (target->pos <= median_a && cheapest->pos <= median_b)
		do_push_top_top(stacks, cheapest, target);
	else if (target->pos > median_a && cheapest->pos > median_b)
		do_push_bottom_bottom(stacks, cheapest, target);
	
	else
		do_push_mixed(stacks, cheapest, target);
}


void	push_b_to_a(t_stacks *stacks)
{
	while (stack_size(stacks->head_b) != 0)
	{
		node_position(stacks, 'a');
		node_position(stacks, 'b');
		find_all_target_2(stacks);
		all_push_cost(stacks);
		stacks->cheapest = find_cheapest(stacks);
		push_top_or_bottom(stacks, stacks->cheapest);
		pa(stacks);
	}
	final_sort(stacks);
}


void	final_sort(t_stacks *stacks)
{
	t_node	*node_min;
	int		size;

	size = stack_size(stacks->head_a);
	node_position(stacks, 'a');
	node_min = find_min(stacks, 'a');


	while (node_min->pos != 0)
	{
		if (node_min->pos <= size / 2)
			ra(stacks);
		else
			rra(stacks);
		
		node_position(stacks, 'a');
	}
}
// void	push_b_to_a(t_stacks *stacks)
// {

// 	while (stack_size(stacks->head_b) != 0)//vérifier la condition
// 	{
// 		node_position(stacks, 'a');
// 		node_position(stacks, 'b');
// 		show_stack(stacks);//to delete
// 		find_min_max(stacks);
// 		find_all_target_2(stacks);
// 		all_push_cost(stacks);
// 		stacks->cheapest = find_cheapest(stacks);
// 		push_top_or_bottom(stacks, stacks->cheapest, NULL);
// 		pa(stacks);
// 	}
// 	node_position(stacks, 'a');
// 	final_sort(stacks);
// 	return ;
// }

// void	final_sort(t_stacks *stacks)
// {
// 	t_node	*node_on_top;
// 	int		median;

// 	node_on_top = find_min(stacks, 'a');
// 	while (node_on_top->pos != 0)
// 	{
// 		node_position(stacks, 'a');
// 		median = find_median(stack_size(stacks->head_a));
// 		if (node_on_top->pos <= median)
// 			ra(stacks);
// 		else
// 			rra(stacks);
// 	}
// 	return ;
// }

// // void	push_top_or_bottom(t_stacks *stacks, t_node *cheapest, t_node *target)
// // {
// // 	int	median_a_is;
// // 	int	median_b_is;

// // 	median_a_is = find_median(stacks->a_len);
// // 	median_b_is = find_median(stacks->b_len);
// // 	target = cheapest->target;//check if useless
// // 	if (cheapest->pos == 0 && target->pos == 0)
// // 		return ;
// // 	if (target->pos <= median_a_is && cheapest->pos <= median_b_is)
// // 		push_top_top(stacks, cheapest, target);
// // 	else if (target->pos > median_a_is && cheapest->pos > median_b_is)
// // 		push_bottom_bottom(stacks, cheapest, target);
// // 	else if (target->pos > median_a_is && cheapest->pos <= median_b_is)
// // 		push_bottom_top(stacks, cheapest, 'a', target);
// // 	else
// // 		push_bottom_top(stacks, cheapest, 'b', target);
// // }
// void	push_top_or_bottom(t_stacks *stacks, t_node *cheapest)
// {
//     t_node *target;
//     int median_a;
//     int median_b;

//     target = cheapest->target;
//     median_a = find_median(stacks->a_len);
//     median_b = find_median(stacks->b_len);

//     // Si les deux sont en haut, on ne fait rien
//     if (cheapest->pos == 0 && target->pos == 0)
//         return ;

//     // CAS 1 : HAUT - HAUT (Tous les deux dans la première moitié)
//     if (target->pos <= median_a && cheapest->pos <= median_b)
//         do_push_top_top(stacks, cheapest, target);
        
//     // CAS 2 : BAS - BAS (Tous les deux dans la seconde moitié)
//     // Attention à bien utiliser '>' pour le bas
//     else if (target->pos > median_a && cheapest->pos > median_b)
//         do_push_bottom_bottom(stacks, cheapest, target);
        
//     // CAS 3 : MIXTE (L'un en haut, l'autre en bas)
//     else
//         do_push_mixed(stacks, cheapest, target);
// }

// void	push_top_top(t_stacks *stacks, t_node *cheapest, t_node *target)
// {
// 	t_node	*bigger;
// 	t_node	*smaller;

// 	if (cheapest->pos >= target->pos)
// 	{
// 		bigger = cheapest;
// 		smaller = target;
// 		do_push_top_top(bigger, smaller, 'b', stacks);
// 	}
// 	else
// 	{
// 		bigger = target;
// 		smaller = cheapest;
// 		do_push_top_top(bigger, smaller, 'a', stacks);
// 	}
// 	return ;
// }

// void	do_push_top_top(t_stacks *stacks, t_node *cheapest, t_node *target)
// {
//     // Tant que les deux ne sont pas en haut (pos != 0), on optimise avec rr
// 	while (cheapest->pos > 0 && target->pos > 0)
// 		rr(stacks);
    
//     // S'il reste du chemin pour A (Target)
// 	while (target->pos > 0)
// 		ra(stacks);
    
//     // S'il reste du chemin pour B (Cheapest)
// 	while (cheapest->pos > 0)
// 		rb(stacks);
// }

// void	push_bottom_bottom(t_stacks *stacks,
// 		t_node *cheapest, t_node *target)
// {
// 	t_node	*bigger;
// 	t_node	*smaller;

// 	target = cheapest->target;
// 	if (cheapest->pos >= target->pos)
// 	{
// 		bigger = cheapest;
// 		smaller = target;
// 		do_push_bottom_bottom_b(bigger, smaller, stacks);
// 	}
// 	else
// 	{
// 		bigger = target;
// 		smaller = cheapest;
// 		do_push_bottom_bottom_a(bigger, smaller, stacks);
// 	}
// 	return ;
// }

// void	do_push_bottom_bottom(t_stacks *stacks, t_node *cheapest, t_node *target)
// {

// 	// int len_a = stack_size(stacks->head_a);
// 	// int len_b = stack_size(stacks->head_b);


    

// 	while (cheapest->pos != 0 && target->pos != 0)
// 		rrr(stacks);

// 	while (cheapest->pos != 0)
// 		rrb(stacks);

//     while (target->pos != 0)
//         rra(stacks);
// }

// void	do_push_bottom_bottom_b(t_node *bigger,
// 		t_node *smaller, t_stacks *stacks)
// {
// 	int	i;

// 	i = 0;
// 	while (i < ((stacks->b_len - bigger->pos) - (stacks->b_len - smaller->pos)))
// 	{
// 		rrb(stacks);
// 		i++;
// 	}
// 	i = -1;
// 	while (i < (stacks->b_len - smaller->pos))
// 	{
// 		rrr(stacks);
// 		i++;
// 	}
// 	return ;
// }

// // void	push_bottom_top(t_stacks *stacks, t_node *cheapest,
// // 		char letter, t_node *target)
// // {
// // 	t_node	*bigger;
// // 	t_node	*smaller;

// // 	if (letter == 'b')
// // 	{
// // 		bigger = target;
// // 		smaller = cheapest;
// // 		do_push_bottom_top(bigger, smaller, letter, stacks);
// // 	}
// // 	else
// // 	{
// // 		bigger = cheapest;
// // 		smaller = target;
// // 		do_push_bottom_top(bigger, smaller, letter, stacks);
// // 	}
// // 	return ;
// // }
// // 

// // Cette fonction gère les deux cas mixtes
// void	do_push_mixed(t_stacks *stacks, t_node *cheapest, t_node *target)
// {
//     int median_a;
//     int median_b;

//     median_a = find_median(stacks->a_len);
//     median_b = find_median(stacks->b_len);

//     // 1. On s'occupe de TARGET (Stack A)
//     if (target->pos <= median_a) // Il est en haut -> ra
//     {
//         while (target->pos != 0)
//             ra(stacks);
//     }
//     else // Il est en bas -> rra
//     {
//         while (target->pos != 0)
//             rra(stacks);
//     }

//     // 2. On s'occupe de CHEAPEST (Stack B)
//     if (cheapest->pos <= median_b) // Il est en haut -> rb
//     {
//         while (cheapest->pos != 0)
//             rb(stacks);
//     }
//     else // Il est en bas -> rrb
//     {
//         while (cheapest->pos != 0)
//             rrb(stacks);
//     }
// }
