/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisano <rpisano@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:54:48 by rpisano           #+#    #+#             */
/*   Updated: 2024/02/28 15:57:38 by rpisano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "libft/libft.h"

typedef struct s_stack
{
	long			num;
	long			i;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

/****************** OPERATIONS ******************/

void	ft_sort(t_stack **stack_a);
void	ft_rotate(t_stack **s, int j, char c);
void	ft_swap(t_stack **s, int j, char c);
void	ft_push(t_stack **dest, t_stack **from, int j, char c);
void	ft_rev_rot(t_stack **s, int j, char c);
void	ft_ss(t_stack **a, t_stack **b, int j);
void	ft_rr(t_stack **a, t_stack **b, int j);
void	ft_rrr(t_stack **a, t_stack **b, int j);

/****************** STACK UTILS ******************/

t_stack	*new_stack_node(long num);
void	free_stack(t_stack **stack);
t_stack	*get_last_node(t_stack *stack_node);
int		get_size(t_stack *stack_node);
int		get_min_num(t_stack *stack_node);
int		get_max_num(t_stack *stack_node);
int		num_index(t_stack *a, int num);
int		pos_b(t_stack *stack_b, int num_to_push);
int		pos_a(t_stack *stack_a, int num_to_push);
void	add_back(t_stack **stack, t_stack *stack_new);

/****************** other UTILS ******************/

int		ft_atoi2(const char *str);
void	ft_freestr(char **lst);
void	ft_error(void);
void	ft_error_ch(void);

/****************** CHECKS ******************/

int		check_input(char **argv);
int		check_sorted(t_stack *stack_a);
int		check_dup(t_stack *a);
void	ft_checker_sub(t_stack **a, t_stack **b, char *line);

/****************** Solvers ******************/

int		ft_count_rarb(t_stack *a, t_stack *b, int num, char c);
int		ft_count_rrarrb(t_stack *a, t_stack *b, int num, char c);
int		ft_count_rrarb(t_stack *a, t_stack *b, int num, char c);
int		ft_count_rarrb(t_stack *a, t_stack *b, int num, char c);
int		ft_choose_rotation(t_stack *a, t_stack *b, char c);

/****************** Appliers ******************/

int		ft_apply_rarrb(t_stack **a, t_stack **b, int c, char s);
int		ft_apply_rrarb(t_stack **a, t_stack **b, int c, char s);
int		ft_apply_rrarrb(t_stack **a, t_stack **b, int c, char s);
int		ft_apply_rarb(t_stack **a, t_stack **b, int c, char s);

#endif
