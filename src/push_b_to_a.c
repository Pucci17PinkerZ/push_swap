/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 17:15:01 by pucci17pink       #+#    #+#             */
/*   Updated: 2026/01/23 12:34:05 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

push_b_to_a(t_stacks *stacks)
{
	node_position(a)
	node_position(b);
	while (stack_size(a) != 0)
	{
		find_min_max(stacks);
		find_all_target(stacks);
		//push_cost(stacks);//not done too//only for B to A
		// find_cheapest();//not done
		push_to_top(stacks);
		do_push();//not done
	}
}



// void	push_a_to_b(t_stacks *stacks)
// {
// 	pb(a, b);
// 	pb(a, b);
// 	node_position(a);
// 	node_position(b);
// 	
// 	sort_three();
// }