/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 15:57:31 by iarrar            #+#    #+#             */
/*   Updated: 2023/03/08 19:17:55 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*dest;
	char	a;

	dest = (char *)str;
	i = 0;
	a = (char)c;
	if (c < 0)
		c = -c;
	while (str[i])
	{
		if (str[i] == a)
			return (&dest[i]);
		else
			i++;
	}
	if (a == '\0')
		return (&dest[i]);
	return (NULL);
}
