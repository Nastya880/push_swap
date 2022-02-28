/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   average_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandroma <tandroma@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 21:38:21 by tandroma          #+#    #+#             */
/*   Updated: 2022/02/24 13:19:37 by tandroma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	void	stack_in_array(int **arr, t_list *stack, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		(*arr)[i] = *(int *)stack->content;
		i++;
		stack = stack->next;
	}
}

/*sortirovka racheskoi
** https://bimlibik.github.io/posts/sorting-algorithm/
*/

static	void	comb_sort(int **arr, t_list *stack, int size)
{
	int		i;
	int		sorted;
	int		tmp;

	stack_in_array(arr, stack, size);
	sorted = 0;
	while (!sorted)
	{
		i = 0;
		sorted = 1;
		while (i < size - 1)
		{
			if ((*arr)[i] > (*arr)[i + 1])
			{
				tmp = (*arr)[i];
				(*arr)[i] = (*arr)[i + 1];
				(*arr)[i + 1] = tmp;
				sorted = 0;
			}
			i++;
		}
	}
}

double	average_arg(t_list *stack, int size)
{
	double		average_arg;
	int			*arr;

	arr = malloc(sizeof(int) * (size));
	comb_sort(&arr, stack, size);
	if (size % 2 != 0)
		average_arg = arr[size / 2];
	else
		average_arg = (arr[size / 2] + arr[size / 2 - 1]) / 2.0;
	free(arr);
	return (average_arg);
}
