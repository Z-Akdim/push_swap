/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transition_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakdim <zakdim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 16:21:56 by zakdim            #+#    #+#             */
/*   Updated: 2021/06/06 18:32:16 by zakdim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*do_rra(t_stack *stack)
{
	t_stack	*tmp;

	if (stack)
	{
		while (stack->next)
			stack = stack->next;
		tmp = stack;
		stack = stack->prev;
		stack->next = NULL;
		while (stack->prev)
			stack = stack->prev;
		stack->prev = tmp;
		tmp->next = stack;
		tmp->prev = NULL;
		write (1, "rra\n", 4);
	}
	return (stack);
}

t_stack	*do_rrb(t_stack *stack)
{
	t_stack	*tmp;

	if (stack)
	{
		while (stack->next)
			stack = stack->next;
		tmp = stack;
		stack = stack->prev;
		stack->next = NULL;
		while (stack->prev)
			stack = stack->prev;
		stack->prev = tmp;
		tmp->next = stack;
		tmp->prev = NULL;
		write (1, "rrb\n", 4);
	}
	return (stack);
}
