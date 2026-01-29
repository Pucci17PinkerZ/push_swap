/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pucci17pinker <pucci17pinker@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 10:57:06 by nfiora-d          #+#    #+#             */
/*   Updated: 2026/01/29 16:30:38 by pucci17pink      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_node
{
	int				nbr;
	int				cost;
	int				pos;
	struct s_node	*next;
	struct s_node	*prev;
	struct s_node	*target;
}	t_node;

typedef struct s_stacks
{
	t_node	*head_a;
	t_node	*head_b;
	t_node	*cheapest;
	t_node	*min_a;
	t_node	*max_a;
	t_node	*min_b;
	t_node	*max_b;
	int		a_len;
	int		b_len;

}	t_stacks;

/* ========================================================================== */
/* ==========================Basic swap fonction==============================*/
/* ========================================================================== */
void		sa(t_stacks *stacks);
void		sb(t_stacks *stacks);
void		sa_2(t_stacks *stacks);
void		sb_2(t_stacks *stacks);
void		ss(t_stacks *stacks);
void		ra(t_stacks *stacks);
void		rb(t_stacks *stacks);
void		ra_2(t_stacks *stacks);
void		rb_2(t_stacks *stacks);
void		rr(t_stacks *stacks);
void		rra(t_stacks *stacks);
void		rrb(t_stacks *stacks);
void		rra_2(t_stacks *stacks);
void		rrb_2(t_stacks *stacks);
void		rrr(t_stacks *stacks);
void		pa(t_stacks *stacks);
void		pb(t_stacks *stacks);
/* ========================================================================== */
/* ==========================Action ==========================================*/
/* ========================================================================== */
void		bring_min_to_top(t_stacks *stacks);
void		sort_three(t_stacks *stacks);
void		sort_five(t_stacks *stacks);
void		push_top_or_bottom(t_stacks *stacks, t_node *cheapest);
void		do_push_top_top(t_stacks *stacks, t_node *cheapest, t_node *target);
void		do_push_bottom_bottom(t_stacks *stacks,
				t_node *cheapest, t_node *target);
void		do_push_mixed(t_stacks *stacks, t_node *cheapest, t_node *target);
void		push_a_to_b(t_stacks *stacks);
void		push_b_to_a(t_stacks *stacks);
void		node_position(t_stacks *stacks, char letter);
void		push_to_top_b(t_stacks *stacks, t_node *target, int stack_len);
void		sort_node(t_stacks *stacks);
void		final_sort(t_stacks *stacks);
/* ========================================================================== */
/* ==========================Analysis=========================================*/
/* ========================================================================== */
t_node		*find_target_b(t_node *b, int nbr, t_node *max_b);
t_node		*find_target_a(t_node *a, int nbr, t_node *min_a);
t_node		*find_cheapest(t_stacks *stacks);
t_node		*find_node_c(t_node *a);
void		find_all_target(t_stacks *stacks);
void		find_all_target_2(t_stacks *stacks);
void		all_push_cost(t_stacks *stacks);
int			push_cost(t_node *node_b, t_node *target, int a_len, int b_len);
int			is_node_sorted(t_node *a);
int			check_stack_order(t_node *a);
/* ========================================================================== */
/* ==========================Clean============================================*/
/* ========================================================================== */
void		clean_exit(t_stacks *stacks);
void		clean_a(t_stacks *stacks);
void		clean_b(t_stacks *stacks);
void		free_tab(char **tab, int j);
/* ========================================================================== */
/* ==========================Utils============================================*/
/* ========================================================================== */
t_node		*find_min(t_stacks *stacks, char letter);
t_node		*find_max(t_stacks *stacks, char letter);
void		find_min_max(t_stacks *stacks);
long long	ft_atoll(const char *nptr);
int			find_median(int stack_size);
int			stack_size(t_node *node);
int			bigger_pos(int node_a_pos, int node_b_pos);
/* ========================================================================== */
/* ==========================Parsing==========================================*/
/* ========================================================================== */
t_node		*last_node(t_node *a);
int			check_input(char **av, t_stacks *stacks);
int			check_args(char **arg_list, t_stacks *stacks);
int			check_doubles(t_stacks *stacks);
int			check_nbr(char *arg);
int			set_node(t_stacks *stacks, int nbr);
int			set_first_node(t_stacks *stacks);
char		**new_args_list(char **av, char **args);
char		**assign_args(int i, int s, char **av, char	**catcher);
int			count_args(char **av, int nbr_arg);

#endif