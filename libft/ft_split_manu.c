/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:30:14 by esuberbi          #+#    #+#             */
/*   Updated: 2024/02/06 23:26:48 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordscount(char const *str, char sep)
{
	int	i;
	int	count;

	if (!str || !str[0])
		return (0);
	i = 1;
	count = 0;
	if (str[0] != sep)
		count++;
	while (str[i])
	{
		if (str[i] != sep && str[i - 1] == sep)
			count++;
		i++;
	}
	return (count);
}

static char	**ft_malloc_words(char const *str, char sep)
{
	int		len;
	char	**tab;

	if (!str)
		return (0);
	len = ft_wordscount(str, sep);
	tab = (char **)malloc(sizeof(*tab) * (len + 1));
	return (tab);
}

static int	ft_next_word_count(char const *str, char sep, int i)
{
	int	count;

	count = 0;
	while (str[i] == sep && str[i])
		i++;
	while (str[i] && str[i] != sep)
	{
		count++;
		i++;
	}
	return (count);
}

static char	**ft_mfree(char **str_tab, int i)
{
	int	j;

	j = 0;
	while (j < i && str_tab[j])
	{
		free(str_tab[j]);
		j++;
	}
	free(str_tab);
	return (0);
}

char	**ft_split(char const *str, char c)
{
	int		word_start;
	int		i;
	int		j;
	char	**tab;

	word_start = 0;
	i = -1;
	tab = ft_malloc_words(str, c);
	if (!tab)
		return (0);
	while (++i < ft_wordscount(str, c))
	{
		j = 0;
		tab[i] = (char *)malloc(ft_next_word_count(str, c, word_start) + 1);
		if (!tab[i])
			return (ft_mfree(tab, i));
		while (str[word_start] && str[word_start] == c)
			word_start++;
		while (str[word_start] && str[word_start] != c)
			tab[i][j++] = str[word_start++];
		tab[i][j] = 0;
	}
	tab[i] = NULL;
	return (tab);
}
