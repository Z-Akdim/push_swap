/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakdim <zakdim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 14:59:24 by zakdim            #+#    #+#             */
/*   Updated: 2021/06/12 16:16:50 by zakdim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_str(char *s1, char c)
{
	int	i;
	int	lengt;
	int	count;

	count = 0;
	i = 0;
	lengt = ft_strlen(s1);
	while (s1[i] == c)
	{
		count++;
		i++;
	}
	i = lengt - 1;
	while (s1[i] == c)
	{
		count++;
		i--;
	}
	return (count);
}

char	*ft_strtrim(char *s1, char set)
{
	char	*str;
	int		len;
	int		i;
	int		j;

	j = 0;
	i = 0;
	str = (char *)malloc(sizeof(char) * ft_strlen(s1)
			- count_str(s1, set) + 1);
	if (str == NULL)
		return (NULL);
	while (s1[i] == set)
		i++;
	len = ft_strlen(s1) - 1;
	while (s1[len] == set)
		len--;
	while (i <= len)
	{
		str[j] = s1[i];
		j++;
		i++;
	}
	str[j] = '\0';
	return (str);
}
