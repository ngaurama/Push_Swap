/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaurama <ngaurama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 20:30:59 by ngaurama          #+#    #+#             */
/*   Updated: 2024/12/23 18:50:26 by ngaurama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                               PUSH_SWAP.H                                  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* ============================= Includes =================================== */
# include "../libft/ft_printf.h"
# include "../libft/get_next_line.h"
# include "../libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <string.h>

/* ============================= Definitions ================================ */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

/* ============================= Structures ================================= */

typedef struct s_Element
{
	int	value;
	int	index;
}		t_Element;

typedef struct s_stacks
{
	int	*stack_a;
	int	size_a;
	int	*stack_b;
	int	size_b;
}		t_stacks;

typedef struct s_rot
{
	int	rot_a;
	int	rot_b;
}		t_rot;

/* ---------------------------- FILE: frees and errors ---------------------- */
void	free_sp(char **split_array);
int		free_err(char *arg, int *stack_a);
void	write_err(void);
void	error_exit(char *error);

/* ---------------------------- FILE: main_helpers -------------------------- */
int		handle_multiple_args(int argc, char **argv, int **stack, int *size);
int		parse_single_arg(char *arg, int **stack, int *size, int i);
int		process_token(char *token, int **stack_a, int *size_a, int argc);
int		main_helper(int argc, char **argv, int **stack_a, int *size_a);

/* ---------------------------- FILE: new_stack ----------------------------- */
void	bubble_sort(t_Element *elements, int size_a);
int		*new_stack(int *stack_a, int size_a);

/* ---------------------------- FILE: utils --------------------------------- */
void	*safe_alloc(size_t bytes);
int		has_duplicates(int *array, int size);
int		is_sorted(int *arr, int size);
int		is_number(char *str);
int		check_empty_input(char **argv);

/* ---------------------------- FILE: calculate ----------------------------- */
int		edge_case(int *stack, int size, int num);
int		find_target_in_a(int num, int *stack, int size);
int		calculate_cost(t_stacks *stacks, int index);

/* ---------------------------- FILE: operations_a -------------------------- */
void	rotate_a(int **stack, int size);
void	rev_rotate_a(int **stack, int size);
void	swap_a(int **stack, int size);
void	push_a(int **stack_a, int **stack_b, int *size_a, int *size_b);

/* ---------------------------- FILE: operations_b -------------------------- */
void	rotate_b(int **stack, int size);
void	rev_rotate_b(int **stack, int size);
void	swap_b(int **stack, int size);
void	push_b(int **stack_a, int **stack_b, int *size_a, int *size_b);

/* ---------------------------- FILE: operations_simul ---------------------- */
void	print_operation(char *operation);
void	simultaneous_rotate(int *stack_a, int size_a, int *stack_b, int size_b);
void	simultaneous_reverse_rotate(int *stack_a, int size_a, int *stack_b,
			int size_b);

/* ---------------------------- FILE: rotation ------------------------------ */
void	non_simul_rotate_a(t_stacks *stacks, int target_a, int rot_a);
void	non_simul_rotate_b(t_stacks *stacks, int cheapest_in_b, int rot_b);
t_rot	simul(t_stacks *stacks, int cheapest_in_b, int target_a, t_rot *rotate);
void	rotation_logic(t_stacks *stacks, int cheapest_in_b, int target_a);

/* ---------------------------- FILE: sort_helpers -------------------------- */
void	shift_till_sorted(int **stack_a, int *size_a);
void	push_back_to_a(t_stacks *stacks, int i, int cheapest_cost);
void	push_to_b(t_stacks *stacks, int i);
int		find_min_index(int *stack, int size);
int		find_max_index(int *stack, int size);

/* ---------------------------- FILE: sort ---------------------------------- */
void	sort_three(int **stack_a, int *size_a);
void	sort_below_three(int **stack_a, int *size_a);
void	sort_stack(t_stacks stacks, int size);

#endif

/* ************************************************************************** */
/*                              END OF FILE                                   */
/* ************************************************************************** */
