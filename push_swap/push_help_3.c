/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_help_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakdim <zakdim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:13:38 by zakdim            #+#    #+#             */
/*   Updated: 2021/06/14 13:07:45 by zakdim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	length;
	char	*tab;

	i = 0;
	if (!s)
		return (0);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	length = ft_strlen(&s[start]);
	if (length >= len)
		length = len;
	tab = (char *)malloc(sizeof(char) * (length + 1));
	if (!tab)
		return (0);
	while (i < length && s[start] != '\0')
		tab[i++] = s[start++];
	tab[i] = '\0';
	return (tab);
}

int	get_spaces(char *str, int ret)
{
	int		i;
	char	**split;

	i = 0;
	split = ft_split(str, ' ');
	while (split && split[i])
	{
		ret++;
		i++;
	}
	ft_free_2(split);
	return (ret);
}

int	get_lengt(char **argv)
{
	int	i;
	int	j;
	int	ret;

	i = 1;
	j = 0;
	ret = 0;
	while (argv[i])
	{
		if (argv[i][0] != '\0')
		{
			j = 0;
			if (ft_strchr(argv[i], ' ') != NULL)
				ret = get_spaces(argv[i], ret);
			else
				ret++;
		}
		i++;
	}
	return (ret);
}

void	get_btween_quots(t_push *vars, char **argv, int i, int *j)
{
	char	**split;
	int		k;

	k = 0;
	split = ft_split(argv[i], ' ');
	while (split[k])
	{
		vars->new_argv[*j] = ft_strdup(split[k]);
		k++;
		*j = *j + 1;
	}
	ft_free_2(split);
}

void	clean_arg(t_push *vars, char **argv)
{
	int	i;
	int	lengt;
	int	j;

	j = 0;
	i = 1;
	lengt = get_lengt(argv);
	vars->new_argv = (char **)malloc(sizeof(char *) * (lengt + 1));
	while (argv[i])
	{
		if (argv[i][0])
		{
			if (ft_strchr(argv[i], ' ') != NULL)
			{
				get_btween_quots(vars, argv, i, &j);
				i++;
			}
			else
				vars->new_argv[j++] = ft_strdup(argv[i++]);
		}
		else
			i++;
	}
	vars->new_argv[j] = NULL;
}
