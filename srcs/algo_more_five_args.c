/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_more_five_args.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandroma <tandroma@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:50:08 by tandroma          #+#    #+#             */
/*   Updated: 2022/02/24 13:19:29 by tandroma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	return_in_a(t_list **stack_a, t_list **stack_b, int size)
{
	if (size == 1)
	{
		pa(stack_b, stack_a);
		return ;
	}
	else if (size == 2)
	{
		if (check_sort(*stack_b, size))
			sb(stack_b);
		pa(stack_b, stack_a);
		pa(stack_b, stack_a);
		return ;
	}
	in_stack_a(stack_b, stack_a, size);
	if (check_sort(*stack_a, ft_lstsize(*stack_a)) == 0)
		algo_more_five_argc(stack_a, stack_b, (size + 1) / 2);
	if (*stack_b)
		return_in_a(stack_a, stack_b, (size + 1) / 2);
}

void	algo_more_five_argc(t_list **stack_a, t_list **stack_b, int size)
{
	int	*part;
	int	i;

	i = 0;
	part = NULL;
	if (create_part(stack_a, stack_b, &part, size) && part)
	{
		while (part[i] != -1)
			i++;
		while (i > 0)
		{
			return_in_a(stack_a, stack_b, part[i - 1]);
			i--;
		}
		free(part);
	}
}
