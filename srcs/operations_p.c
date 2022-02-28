/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandroma <tandroma@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 12:42:28 by tandroma          #+#    #+#             */
/*   Updated: 2022/02/24 13:19:56 by tandroma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*new_stack;

	if (!(*stack_a || !stack_b))
		return ;
	new_stack = *stack_a;
	*stack_a = (*stack_a)->next;
	new_stack->next = NULL;
	ft_lstadd_front(stack_b, new_stack);
	ft_putendl_fd("pb", 1);
}

void	pa(t_list **stack_b, t_list **stack_a)
{
	t_list	*tmp;

	if (!(*stack_b || !stack_a))
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = NULL;
	ft_lstadd_front(stack_a, tmp);
	ft_putendl_fd("pa", 1);
}
