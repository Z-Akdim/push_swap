/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chack_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakdim <zakdim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 17:40:36 by zakdim            #+#    #+#             */
/*   Updated: 2021/06/14 09:39:16 by zakdim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_arg_error(char **ag)
{
	int	i;
	int	j;

	i = 0;
	while (ag[i])
	{
		j = 0;
		while ((ft_isdigit(ag[i][j])) == 1 && ag[i][j])
			j++;
		if ((ag[i][j] == '-' || ag[i][j] == '+') && ft_isdigit(ag[i][j + 1]))
		{
			j++;
			while ((ft_isdigit(ag[i][j]) == 1))
				j++;
		}
		if (ag[i][j] && ft_isdigit(ag[i][j]) == 0)
		{
			write (2, "Error\n", 6);
			exit (-1);
		}
		i++;
	}
}

void	line_error(t_push *stack)
{
	int	i;

	i = 0;
	while (i < stack->len_stack - 1)
	{
		if (stack->table[i] == stack->table[i + 1])
		{
			write (2, "Error\n", 6);
			free_table(stack);
			exit (-1);
		}
		i++;
	}
}
