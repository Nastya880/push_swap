/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_less_four_args.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandroma <tandroma@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:49:05 by tandroma          #+#    #+#             */
/*   Updated: 2022/02/24 13:31:39 by tandroma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	first_var(t_list **stack)
{
	rra(stack);
	sa(stack);
}

static void	second_var(t_list **stack)
{
	sa(stack);
	rra(stack);
}

void	algo_less_four_argc(t_list **stack, int size)
{
	int	first;
	int	second;
	int	third;

	first = *(int *)(*stack)->content;
	second = *(int *)((*stack)->next)->content;
	third = *(int *)(((*stack)->next)->next)->content;
	if (size == 2)
	{
		sa(stack);
		return ;
	}
	if (first < second && first < third && second > third)
		first_var(stack);
	else if (first > second && first > third && second > third)
		second_var(stack);
	else if (first > second && first > third && second < third)
		ra(stack);
	else if (first > second && first < third)
		sa(stack);
	else if (first < second && first > third)
		rra(stack);
}
