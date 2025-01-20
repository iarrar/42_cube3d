/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <event@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 10:07:51 by iarrar            #+#    #+#             */
/*   Updated: 2024/02/21 14:35:44 by event            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

char	*ft_strtroum(const char *s, int c)
{
	char	set[2];

	set[0] = c;
	set[1] = '\0';
	return (ft_strtrim(s, set));
}

int	ft_first(char const *str, char c)
{
	int			i;
	int			j;
	char		*s;

	s = ft_strtroum(str, c);
	j = 0;
	i = 0;
	if (s[0] == '\0')
	{
		free(s);
		return (-1);
	}
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c)
		{
			j++;
			i++;
		}
		else
			i++;
	}
	free(s);
	return (j);
}

char	**ft_free(char **str, int c)
{
	int	i;

	i = c;
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	free(str);
	return (NULL);
}

char	**ft_segment(char *str, char c)
{
	int		i;
	int		j;
	int		x;
	char	**dest;

	x = 0;
	i = 0;
	j = 0;
	dest = ft_calloc(sizeof (char *), (ft_first(str, c) + 2));
	if (!str)
		return (NULL);
	while (str[i] && x <= ft_first(str, c))
	{
		while (str[i] != c && str[i])
			i++;
		dest[x] = ft_substr(str, j, i - j);
		if (!dest[x])
			return (ft_free(dest, x));
		while (str[i] == c)
			i++;
		j = i;
		x++;
	}
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char		**dest;
	char		*s1;

	s1 = ft_strtroum(s, c);
	if (!s1)
		return (NULL);
	dest = ft_segment(s1, c);
	free(s1);
	return (dest);
}
