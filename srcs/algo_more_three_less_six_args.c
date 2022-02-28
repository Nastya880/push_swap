/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_more_three_less_six_args.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandroma <tandroma@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 12:31:01 by tandroma          #+#    #+#             */
/*   Updated: 2022/02/24 17:12:46 by tandroma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	first_step(t_list	**stack_a, t_list **stack_b, int average)
{
	if (*(int *)(*stack_a)->content < average)
		pb(stack_a, stack_b);
	else if (ft_lstsize(*stack_b) < 2 && ft_lstsize(*stack_a) > 3)
	{
		if (*(int *)(*stack_a)->next->content < average)
			ra(stack_a);
		else
			rra(stack_a);
	}
	else
		algo_less_four_argc(stack_a, ft_lstsize(*stack_a));
}

void	algo_more_three_less_six_argc(t_list **stack_a, t_list **stack_b)
{
	double	average;

	average = average_arg(*stack_a, ft_lstsize(*stack_a));
	while (check_sort(*stack_a, ft_lstsize(*stack_a)) == 0)
		first_step(stack_a, stack_b, average);
	while (*stack_b)
	{
		if (check_sort(*stack_b, ft_lstsize(*stack_b)) && (*stack_b)->next)
			sb(stack_b);
		else
			pa(stack_b, stack_a);
		if (check_sort(*stack_a, ft_lstsize(*stack_a)) == 0)
			sa(stack_a);
	}
}
