/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 10:57:06 by nfiora-d          #+#    #+#             */
/*   Updated: 2026/01/22 16:12:56 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H


#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

typedef struct s_node
{
	int	nbr;
	int	cost;
	int pos;
	struct s_node *next;
	struct s_node *prev;
	struct s_node *target;
}	t_node;

typedef struct s_stack
{
	t_node	*head_a;
	t_node	*head_b;
	§t_node	cheapest;
	t_node	*min_a;
	t_node	*max_a;
	t_node	*min_b;
	t_node	*max_b;
	int	a_len;
	int	b_len;
}	t_stack;

//fonction de swap
void	sa(t_node *a);
void	sb(t_node *a);
void	ss(t_node *a, t_node *b);
void	ra(t_node *a);
void	rb(t_node *a);
void	rr(t_node *a, t_node *b);
void	rra(t_node *a);
void	rrb(t_node *a);
void	rrr(t_node *a, t_node *b);
void	pa(t_node *a, t_node *b);
void	pb(t_node *a, t_node *b);

//turk algo
int		sort_node(t_node *a, t_node *b);
int		check_stack_order(t_node *a);
void	node_position(t_node *a);
void	push_a_to_b(t_stacks *stacks);
t_node	*find_min(t_node *head);
t_node	*find_max(t_node *head);

//fonction annexe au swap
t_node	*find_node_c(t_node *a);

// fonction de clean
void	clean_exit(t_stacks *stacks);
void	clean_a(t_node *a);
void	clean_b(t_node *b);
//fonction de tri

//autre fonctions
int		check_input(int ac, char **av, t_node *a);
int		check_args(char **arg_list, t_node *a);
int		check_nbr(char *arg);
int		set_node(t_node *a, int nbr);
t_node	*last_node(t_node *a);
int		stack_size(t_node *node);

#endif