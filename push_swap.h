/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 10:57:06 by nfiora-d          #+#    #+#             */
/*   Updated: 2026/01/15 17:37:06 by pucci17pink      ###   ########.fr       */
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
	struct t_node *next;
	struct t_node *prev;
}	t_node;

//fonction de swap
void	sa();
void	sb();
void	ss();
void	ra();
void	rb();
void	rr();
void	rra();
void	rrb();
void	rrr();
void	pa();
void	pb();


// fonction de clean

//fonction de tri

//autre fonctions
int	check_input(int ac, char **av, t_node *a);
int	check_args(char **arg_list, t_node *a);
int	check_nbr(char *arg);
void	set_node(t_node *a, int nbr);
t_node	*last_node(t_node *a);

#endif