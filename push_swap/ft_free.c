/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakdim <zakdim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 09:04:32 by zakdim            #+#    #+#             */
/*   Updated: 2021/06/14 09:43:40 by zakdim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_2(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_free_stack(t_stack *stack)
{
	t_stack	*tmp;

	stack = get_head(stack);
	while (stack)
	{
		if (stack)
			tmp = stack->next;
		free(stack);
		stack = tmp;
	}
	stack = NULL;
}

void	free_table(t_push *push)
{
	if (push->table)
		free(push->table);
	push->table = NULL;
}

int	get_lengt_new_arg(char **new_argv)
{
	int	i;

	i = 0;
	while (new_argv[i])
		i++;
	return (i);
}

void	fill_table(t_push *push)
{
	while (push->new_argv[push->i])
	{
		push->table[push->j] = ft_atoi(push->new_argv[push->i],
				&push->chack_error);
		if (push->chack_error == 1)
		{
			free_table(push);
			exit (-1);
		}
		push->i++;
		push->j++;
	}	
}
