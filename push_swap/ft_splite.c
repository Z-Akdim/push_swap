/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakdim <zakdim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 14:40:40 by zakdim            #+#    #+#             */
/*   Updated: 2021/06/14 12:20:47 by zakdim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	c_word(char *str, char c)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (str[++i])
	{
		if (str[i] == c && str[i + 1] != c)
			count++;
		if (str[i] != c && str[i + 1] == '\0')
			count++;
	}
	return (count);
}

static	void	ft_free(char **tab, char *str)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	free(str);
}

static	char	*remplir(char *s, int *k, char c)
{
	int		i;
	int		start;
	int		end;
	char	*str;
	int		startt;

	i = *k;
	while (s[i] == c)
		i++;
	start = i;
	startt = i;
	while (s[i] != c && s[i])
		i++;
	end = i;
	*k = i;
	while (startt < end)
		startt++;
	str = ft_substr(s, start, (end - start));
	if (str == NULL)
		return (NULL);
	return (str);
}

char	**ft_split(const char *s, char c)
{
	char	*str;
	char	**tab;
	int		i;
	int		j;
	int		k;

	i = -1;
	str = ft_strtrim((char *)s, c);
	if (str == NULL)
		return (NULL);
	j = c_word(str, c);
	tab = (char **)malloc((j + 1) * sizeof(char *));
	k = 0;
	while (++i < j)
	{
		tab[i] = remplir(str, &k, c);
		if (tab[i] == NULL)
		{
			ft_free(tab, str);
			return (0);
		}
	}
	tab[i] = NULL;
	free(str);
	return (tab);
}
