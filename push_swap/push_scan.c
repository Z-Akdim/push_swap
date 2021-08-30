/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_scan.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakdim <zakdim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 16:31:32 by zakdim            #+#    #+#             */
/*   Updated: 2021/06/14 12:27:06 by zakdim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_scan_top(t_push *push, int chunk_size, int j)
{
	int	ret;
	int	indice;
	int	moves;

	moves = 0;
	ret = 0;
	push->a = get_head(push->a);
	while (ret < push->len_stack)
	{
		indice = j;
		while (indice < chunk_size)
		{
			if (push->a->num == push->table[indice])
				return (moves);
			indice++;
		}
		push->a = push->a->next;
		ret++;
		moves++;
	}
	return (-1);
}

int	get_scan_end(t_push *push, int chunk_size, int j)
{
	int	ret;
	int	moves;
	int	indice;

	moves = 0;
	ret = 0;
	push->a = get_end(push->a);
	while (ret < push->len_stack)
	{
		indice = j;
		while (indice < chunk_size)
		{
			if (push->a->num == push->table[indice])
				return (moves);
			indice++;
		}
		push->a = push->a->prev;
		ret++;
		moves++;
	}
	return (-1);
}

void	push_a_to_b(t_push *push, int chunk_size, int j)
{
	int	move_top;
	int	move_end;

	move_top = get_scan_top(push, chunk_size, j);
	move_end = get_scan_end(push, chunk_size, j);
	if (move_top <= move_end)
	{
		while (move_top-- > 0)
			push->a = do_ra(push->a);
		do_pb(push);
	}
	else
	{
		while (move_end-- >= 0)
			push->a = do_rra(push->a);
		do_pb(push);
	}
	push->len_stack = stack_lent(push->a);
}

void	last_sort(t_push *push, int pos_num, int midle_stack)
{
	int	big_nbr;
	int	i;
	int	stack_lengt;

	i = 0;
	stack_lengt = stack_lent(push->b);
	while (i < stack_lengt)
	{
		midle_stack = stack_lent(push->b) / 2;
		big_nbr = get_big_nbr(push->b);
		pos_num = get_big_nbr_pos(push->b, big_nbr);
		if (pos_num <= midle_stack)
		{
			while (pos_num-- > 0)
				push->b = do_rb(push->b);
			do_pa(push);
		}
		else
		{
			while (pos_num++ < stack_lent(push->b))
				push->b = do_rrb(push->b);
			do_pa(push);
		}
		i++;
	}
}
