/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandroma <tandroma@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:50:35 by tandroma          #+#    #+#             */
/*   Updated: 2022/02/24 16:41:11 by tandroma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	error_so_exit(t_list **stack_a)
{
	if (stack_a)
		ft_lstclear(stack_a, free);
	ft_putendl_fd("Error", 1);
	exit (1);
}

static	void	check_duplicate(int num, t_list *stack_a)
{
	while (stack_a)
	{
		if (num == *(int *)stack_a->content)
			error_so_exit(&stack_a);
		stack_a = stack_a->next;
	}
}

static int	input_valid_symbol(char *str, t_list **stack)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	if (str[0] == '-')
		i++;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] == '\0')
		return (1);
	error_so_exit(stack);
	return (0);
}

void	create_stack(char **argv, t_list **stack_a)
{
	int		i;
	long	*num;
	t_list	*new;

	i = 0;
	while (argv[++i])
	{
		if (input_valid_symbol(argv[i], stack_a))
		{
			num = malloc(sizeof(long));
			if (!num)
				error_so_exit(stack_a);
			*num = ft_atoi(argv[i]);
			check_duplicate(*num, *stack_a);
			if ((*num < -2147483648 || *num > 2147483647))
			{
				free(num);
				error_so_exit(stack_a);
			}
			new = ft_lstnew((int *)num);
			ft_lstadd_back(stack_a, new);
		}
		else
			error_so_exit(stack_a);
	}
}
