/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_help_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakdim <zakdim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 16:28:27 by zakdim            #+#    #+#             */
/*   Updated: 2021/06/09 12:22:54 by zakdim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_lent(t_stack *stack)
{
	int		i;
	t_stack	*tmp;

	tmp = stack;
	i = 0;
	while (tmp && tmp->prev)
		tmp = tmp->prev;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

t_stack	*get_head(t_stack *stack)
{
	while (stack && stack->prev)
		stack = stack->prev;
	return (stack);
}

t_stack	*get_end(t_stack *stack)
{
	while (stack && stack->next)
		stack = stack->next;
	return (stack);
}

int	chack_if_sort(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack && stack->prev)
		stack = stack->prev;
	while (stack && stack->next)
	{
		if (stack->num < stack->next->num)
			stack = stack->next;
		else
			return (1);
	}
	return (0);
}

void	sort_table(t_push *stack)
{
	int long	tmp;
	int			i;

	tmp = 0;
	i = 0;
	while (i < stack->len_stack - 1)
	{
		if (stack->table[i] > stack->table[i + 1])
		{
			tmp = stack->table[i];
			stack->table[i] = stack->table[i + 1];
			stack->table[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
}
