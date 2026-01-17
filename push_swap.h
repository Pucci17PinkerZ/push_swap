/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 10:57:06 by nfiora-d          #+#    #+#             */
/*   Updated: 2026/01/17 19:01:52 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H


#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "../libft/libft.h"
#include "../ft_printf/ft_printf.h"

typedef struct s_node
{
	int	nbr;
	int	cost;
	int pos;
	struct s_node *next;
	struct s_node *prev;
}	t_node;

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
void	pa(t_node *a);
void	pb(t_node *a);

//fonction annexe au swap
t_node	*find_node_c(t_node *a);

// fonction de clean

//fonction de tri

//autre fonctions
int	check_input(int ac, char **av, t_node *a);
int	check_args(char **arg_list, t_node *a);
int	check_nbr(char *arg);
int	set_node(t_node *a, int nbr);
t_node	*last_node(t_node *a);

#endif