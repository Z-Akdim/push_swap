/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transitions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakdim <zakdim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 15:56:12 by zakdim            #+#    #+#             */
/*   Updated: 2021/06/11 18:06:02 by zakdim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*do_sa(t_stack *stack)
{
	long int	swap;

	swap = 0;
	while (stack && stack->prev)
		stack = stack->prev;
	if (stack && stack->next != NULL)
	{
		swap = stack->num;
		stack->num = stack->next->num;
		stack->next->num = swap;
	}
	write(1, "sa\n", 3);
	return (stack);
}

t_stack	*do_sb(t_stack *stack)
{
	long int	swap;

	swap = 0;
	while (stack->prev)
		stack = stack->prev;
	if (stack && stack->next != NULL)
	{
		swap = stack->num;
		stack->num = stack->next->num;
		stack->next->num = swap;
	}
	write(1, "sb\n", 3);
	return (stack);
}

t_stack	*do_ra(t_stack *stack)
{
	t_stack		*swap;

	while (stack->prev)
		stack = stack->prev;
	if (stack && stack->next != NULL)
	{
		swap = stack;
		if (stack->next)
		{
			stack = stack->next;
			stack->prev = NULL;
		}
		while (stack && stack->next)
			stack = stack->next;
		stack->next = swap;
		swap->prev = stack;
		swap->next = NULL;
	}
	while (stack->prev)
		stack = stack->prev;
	write (1, "ra\n", 3);
	return (stack);
}

t_stack	*do_rb(t_stack *stack)
{
	t_stack		*swap;

	while (stack->prev)
		stack = stack->prev;
	if (stack && stack->next != NULL)
	{
		swap = stack;
		if (stack->next)
		{
			stack = stack->next;
			stack->prev = NULL;
		}
		while (stack && stack->next)
			stack = stack->next;
		stack->next = swap;
		swap->prev = stack;
		swap->next = NULL;
	}
	while (stack->prev)
		stack = stack->prev;
	write (1, "rb\n", 3);
	return (stack);
}
