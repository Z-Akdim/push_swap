/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solutions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakdim <zakdim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 16:33:37 by zakdim            #+#    #+#             */
/*   Updated: 2021/06/14 12:27:48 by zakdim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solution_for_fiveless_2(t_push *push, int j)
{
	j = stack_lent(push->a);
	if (j == 2)
	{
		push->a = get_head(push->a);
		if (push->a->num > push->a->next->num)
			do_sa(push->a);
		push->b = get_head(push->b);
		if (push->b->num < push->b->next->num)
			push->b = do_sb(push->b);
		do_pa(push);
		do_pa(push);
	}
	else
	{
		push->a = solution_for_three(push->a);
		push->b = get_head(push->b);
		if (push->b->num < push->b->next->num)
			push->b = do_sb(push->b);
		do_pa(push);
		do_pa(push);
	}
	push->a = get_head(push->a);
}

void	solution_for_fiveless(t_push *push)
{
	int	median_stack;
	int	j;

	j = 0;
	median_stack = push->table[push->len_stack / 2];
	push->a = get_head(push->a);
	while (j < push->len_stack)
	{
		if (push->a->num < median_stack)
			do_pb(push);
		else
			push->a = do_ra(push->a);
		push->a = get_head(push->a);
		j++;
	}
	solution_for_fiveless_2(push, 0);
}

void	solution_for_more_five_2(t_push *push)
{
	if ((stack_lent(push->a)) == 3)
		push->a = solution_for_three(push->a);
	else if ((stack_lent(push->a)) == 2)
	{
		push->a = get_head(push->a);
		if (push->a->num > push->a->next->num)
			push->a = do_sa(push->a);
	}
	while (push->a)
		do_pb(push);
	last_sort(push, 0, 0);
}

void	solution_for_more_five(t_push *push, int nbr_chunk)
{
	int	chunk_size;
	int	i;
	int	j;
	int	inc;

	j = 0;
	i = 0;
	chunk_size = push->len_stack / nbr_chunk;
	inc = chunk_size;
	while (i < nbr_chunk)
	{
		while (j < chunk_size)
		{
			push_a_to_b(push, chunk_size, 0);
			j++;
		}
		chunk_size += inc;
		i++;
	}
	solution_for_more_five_2(push);
}

t_stack	*solution_for_three(t_stack *stack)
{
	stack = get_head(stack);
	if (stack->num > stack->next->num && stack->num < stack->next->next->num)
		stack = do_sa(stack);
	else if (stack->num > stack->next->num
		&& stack->next->num > stack->next->next->num)
	{
		stack = do_sa(stack);
		stack = do_rra(stack);
	}
	else if ((stack->num > stack->next->num)
		&& (stack->next->num < stack->next->next->num))
		stack = do_ra(stack);
	else if ((stack->num < stack->next->num)
		&& (stack->next->num > stack->next->next->num))
	{
		stack = do_sa(stack);
		stack = do_ra(stack);
	}	
	else if ((stack->num < stack->next->num)
		&& (stack->next->num > stack->next->next->num))
		stack = do_rra(stack);
	return (stack);
}
