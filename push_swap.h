/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfiora-d <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 10:57:06 by nfiora-d          #+#    #+#             */
/*   Updated: 2025/10/03 12:43:43 by nfiora-d         ###   ####lausanne.ch   */
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

#endif