/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:34:56 by iarrar            #+#    #+#             */
/*   Updated: 2023/03/14 21:24:58 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_start(const char *str, const char *set)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if (ft_strchr(set, str[i]) == NULL)
			break ;
		i++;
	}
	return (i);
}

int	ft_finish(const char *str, const char *set)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(str);
	i = 0;
	while (i <= len - 1)
	{
		if (ft_strchr(set, str[len - 1 - i]) == NULL)
			break ;
		i++;
	}
	return (len - i);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	int		beg;
	int		fin;
	char	*str;
	int		i;

	i = 0;
	beg = ft_start(s1, set);
	fin = ft_finish(s1, set);
	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	if (beg >= fin)
		return ("");
	str = malloc(sizeof(char) * (fin - beg + 1));
	while (i < fin - beg)
	{
		str[i] = s1[beg + i];
		i++;
	}
	return (str);
}
