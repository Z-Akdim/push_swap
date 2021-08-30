/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakdim <zakdim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 18:26:39 by zakdim            #+#    #+#             */
/*   Updated: 2021/06/14 12:26:06 by zakdim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_stack(void)
{
	t_stack	*new_nbr;

	new_nbr = malloc(sizeof(t_stack));
	new_nbr->next = NULL;
	new_nbr->prev = NULL;
	return (new_nbr);
}

t_stack	*next_stack(int value, t_stack *stack)
{
	t_stack	*next;

	while (stack->next)
		stack = stack->next;
	next = new_stack();
	next->num = value;
	next->prev = stack;
	stack->next = next;
	return (stack);
}

t_stack	*copy_table_to_stack(int *tbl, int len)
{
	t_stack	*stack;
	int		i;

	i = 1;
	stack = new_stack();
	stack->num = tbl[0];
	while (i < len)
	{
		stack = next_stack(tbl[i], stack);
		i++;
	}
	return (stack);
}

int	push_swap(t_push *push, int lent)
{
	push->a = copy_table_to_stack(push->table, lent);
	push->len_stack = stack_lent(push->a);
	sort_table(push);
	line_error(push);
	if ((chack_if_sort(push->a)) == 0)
	{
		ft_free_stack(push->a);
		return (1);
	}
	else if (push->len_stack == 2)
	{
		if (push->a->num > push->a->next->num)
			push->a = do_sa(push->a);
	}
	else if (push->len_stack == 3)
		push->a = solution_for_three(push->a);
	else if (push->len_stack <= 5)
		solution_for_fiveless(push);
	else if (push->len_stack > 5 && push->len_stack <= 100)
		solution_for_more_five(push, 5);
	else if (push->len_stack > 5 && push->len_stack <= 500)
		solution_for_more_five(push, 13);
	return (0);
}

int	main(int ac, char **argv)
{
	t_push	push;

	if (ac == 1)
		exit (-1);
	push.j = 0;
	push.i = 0;
	push.b = NULL;
	push.chack_error = 0;
	clean_arg(&push, argv);
	push.lent = get_lengt_new_arg(push.new_argv);
	push.table = (int *)malloc(sizeof(int) *(push.lent + 1));
	check_arg_error(push.new_argv);
	fill_table(&push);
	if ((push_swap(&push, push.lent)) == 1)
		exit (-1);
	ft_free_2(push.new_argv);
	ft_free_stack(push.a);
	free_table(&push);
	return (0);
}
