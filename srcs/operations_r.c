/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_r.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandroma <tandroma@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 12:50:58 by tandroma          #+#    #+#             */
/*   Updated: 2022/02/24 13:20:03 by tandroma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_list **stack_a)
{
	t_list	*new_stack;

	new_stack = *stack_a;
	*stack_a = (*stack_a)->next;
	new_stack->next = NULL;
	ft_lstadd_back(stack_a, new_stack);
	ft_putendl_fd("ra", 1);
}

void	rb(t_list **stack_b)
{
	t_list	*new_stack;

	new_stack = *stack_b;
	*stack_b = (*stack_b)->next;
	new_stack->next = NULL;
	ft_lstadd_back(stack_b, new_stack);
	ft_putendl_fd("rb", 1);
}

static void	rrotate_stack(t_list **stack)
{
	t_list	*new_stack;
	t_list	*new_last_stack;

	new_last_stack = *stack;
	while (new_last_stack->next->next)
		new_last_stack = new_last_stack->next;
	new_stack = ft_lstlast(*stack);
	ft_lstadd_front(stack, new_stack);
	new_last_stack->next = NULL;
}

void	rra(t_list **stack_a)
{
	rrotate_stack(stack_a);
	ft_putendl_fd("rra", 1);
}

void	rrb(t_list **stack_b)
{
	rrotate_stack(stack_b);
	ft_putendl_fd("rrb", 1);
}

// void	rotate_stacks(t_list **stack_a, t_list **stack_b)
// {
// 	rotate_stack(stack_a);
// 	rotate_stack(stack_b);
// 	ft_putstr_fd("rr\n", 1);
// }

// void	rrotate_stacks(t_list **stack_a, t_list **stack_b)
// {
// 	rrotate_stack(stack_a);
// 	rrotate_stack(stack_b);
// 	ft_putstr_fd("rrr\n", 1);
// }
