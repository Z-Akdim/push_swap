/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakdim <zakdim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 18:20:51 by zakdim            #+#    #+#             */
/*   Updated: 2021/06/14 09:52:25 by zakdim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s == 0)
		return ;
	while (s[i])
		write(fd, &s[i++], 1);
}

long long	ft_atoi(const char *str, int *check_error)
{
	int			i;
	long long	res;
	int			sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\r'
			|| str[i] == '\f' || str[i] == '\v') && str[i])
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	if ((res * sign) > 2147483647 || (res * sign) < -2147483648)
	{
		ft_putstr_fd("Error\n", 2);
		*check_error = 1;
	}
	return (res * sign);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	get_big_nbr(t_stack *stack)
{
	t_stack	*tmp;
	int		ret;

	tmp = stack;
	tmp = get_head(stack);
	ret = tmp->num;
	while (tmp)
	{
		if (tmp->num > ret)
			ret = tmp->num;
		tmp = tmp->next;
	}
	return (ret);
}

int	get_big_nbr_pos(t_stack *stack, int nbr)
{
	t_stack	*tmp;
	int		ret;

	ret = 0;
	tmp = stack;
	tmp = get_head(stack);
	while (tmp)
	{
		if (tmp->num == nbr)
			return (ret);
		ret++;
		tmp = tmp->next;
	}
	return (-1);
}
