/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandroma <tandroma@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 222/01/28 12:30:02 by tandroma          #+#    #+#             */
/*   Updated: 2022/02/13 17:49:11 by tandroma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

/*
** operations
*/

void	sa(t_list **stack);
void	sb(t_list **stack);
void	ss(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_b, t_list **stack_a);
void	pb(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);

/*
** algorithms
*/

void	algo_less_four_argc(t_list **stack, int argc);
void	algo_more_three_less_six_argc(t_list **stack_a, t_list **stack_b);
void	algo_more_five_argc(t_list **stack_a, t_list **stack_b, int size);

/*
** other functions
*/

double	average_arg(t_list *stack, int size);
int		check_sort(t_list *stack, int size);
int		create_part(t_list **stack_a, t_list **stack_b, int **chunks, int size);
void	in_stack_a(t_list **stack_b, t_list **stack_a, int size);
void	create_stack(char **argv, t_list **stack_a);

#endif
