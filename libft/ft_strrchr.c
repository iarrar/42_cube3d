/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 16:04:52 by iarrar            #+#    #+#             */
/*   Updated: 2023/03/06 14:44:30 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*dest;
	char	a;

	a = (char)c;
	i = ft_strlen(str);
	dest = (char *)str;
	if (c < 0)
		c = -c;
	if (c == 0)
		return (&dest[i]);
	while (i >= 0)
	{
		if (dest[i] == a)
			return (&dest[i]);
		else
			i--;
	}
	return (NULL);
}
