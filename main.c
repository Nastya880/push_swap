/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandroma <tandroma@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 12:30:28 by tandroma          #+#    #+#             */
/*   Updated: 2022/02/24 13:26:42 by tandroma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static	void	end_and_exit(t_list **stack_a, t_list **stack_b)
{
	if (stack_a)
		ft_lstclear(stack_a, free);
	if (stack_b)
		ft_lstclear(stack_b, free);
	exit (0);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		exit (0);
	create_stack(argv, &stack_a);
	if (argc == 2)
		end_and_exit(&stack_a, &stack_b);
	if (!check_sort(stack_a, ft_lstsize(stack_a)))
	{
		if (argc <= 4)
			algo_less_four_argc(&stack_a, argc - 1);
		else if (argc <= 6)
			algo_more_three_less_six_argc(&stack_a, &stack_b);
		else
			algo_more_five_argc(&stack_a, &stack_b, argc - 1);
	}
	end_and_exit(&stack_a, &stack_b);
}
