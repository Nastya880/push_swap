/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_parts.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandroma <tandroma@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 12:24:32 by tandroma          #+#    #+#             */
/*   Updated: 2022/02/24 13:20:21 by tandroma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	create_first_part(int **part, int size)
{
	int	*new_arr;

	new_arr = NULL;
	new_arr = malloc(sizeof(int) * 2);
	if (!new_arr)
		return ;
	new_arr[0] = size;
	new_arr[1] = -1;
	*part = new_arr;
}

static void	overwriting_part(int **part, int size)
{
	int	size_part;
	int	*new_part;
	int	i;

	i = 0;
	size_part = 0;
	new_part = NULL;
	if (*part)
	{
		while (part[0][size_part] != -1)
			size_part++;
		new_part = malloc(sizeof(int) * (size_part + 2));
		if (!new_part)
			return ;
		while (i++ != size_part)
			new_part[i - 1] = part[0][i - 1];
		new_part[size_part] = size;
		new_part[size_part + 1] = -1;
		free(*part);
		*part = new_part;
	}
	else
		create_first_part(part, size);
}

static void	in_stack_b(t_list **stack_a, t_list **stack_b, int size)
{
	double	average;
	int		quantity_reverse;

	average = average_arg(*stack_a, size);
	quantity_reverse = 0;
	size = size / 2;
	while (size > 0)
	{
		if (*(int *)(*stack_a)->content < average)
		{
			pb(stack_a, stack_b);
			size--;
		}
		else
		{
			ra(stack_a);
			quantity_reverse++;
		}
	}
	while (quantity_reverse-- != 0)
		rra(stack_a);
}

void	in_stack_a(t_list **stack_b, t_list **stack_a, int size)
{
	double	average;
	int		quantity_reverse;

	average = average_arg(*stack_b, size);
	quantity_reverse = 0;
	size = size / 2;
	while (size > 0)
	{
		if (*(int *)(*stack_b)->content > average)
		{
			pa(stack_b, stack_a);
			size--;
		}
		else
		{
			rb(stack_b);
			quantity_reverse++;
		}
	}
	while (quantity_reverse-- != 0)
		rrb(stack_b);
}

int	create_part(t_list **stack_a, t_list **stack_b, int **part, int size)
{
	if (size == 2)
	{
		if (*(int *)(*stack_a)->next->content < *(int *)(*stack_a)->content)
			sa(stack_a);
		return (1);
	}
	else if (size == 1)
		return (1);
	else
	{
		in_stack_b(stack_a, stack_b, size);
		overwriting_part(part, size / 2);
		create_part(stack_a, stack_b, part, (size + 1) / 2);
		return (1);
	}
}
