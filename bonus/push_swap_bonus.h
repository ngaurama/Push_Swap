/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:43:54 by ngaurama          #+#    #+#             */
/*   Updated: 2024/12/23 18:50:34 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                           PUSH_SWAP_BONUS.H                                */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

/* ============================= INCLUDES =================================== */

# include "../src/push_swap.h"

/* ============================= OPERATIONS A =============================== */

void	ra(int **stack, int size);
void	rra(int **stack, int size);
void	sa(int **stack, int size);
void	pa(int **stack_a, int **stack_b, int *size_a, int *size_b);

/* ============================= OPERATIONS B =============================== */

void	rb(int **stack, int size);
void	rrb(int **stack, int size);
void	sb(int **stack, int size);
void	pb(int **stack_a, int **stack_b, int *size_a, int *size_b);

/* ====================== OPERATIONS SIMULTANEOUS =========================== */

void	ss(int *stack_a, int size_a, int *stack_b, int size_b);
void	rr(int *stack_a, int size_a, int *stack_b, int size_b);
void	rrr(int *stack_a, int size_a, int *stack_b, int size_b);

/* ============================ EXECUTE MOVES =============================== */

int		execute_move(char *move, t_stacks *stacks);
void	simul_move(char *move, t_stacks *stacks);

/* ========================== FREES AND ERRORS ============================== */

void	free_stacks(t_stacks *stacks);
void	write_err(void);

/* ================================ UTILS =================================== */

int		init_stacks(int argc, t_stacks *stacks);
int		handle_multiple_args(int argc, char **argv, int **stack, int *size);
int		process_input_moves(t_stacks *stacks);
int		ft_strcmp(const char *s1, const char *s2);
void	check_ok(t_stacks stacks);

#endif

/* ************************************************************************** */
/*                          END OF PUSH_SWAP_BONUS.H                          */
/* ************************************************************************** */
