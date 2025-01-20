/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 16:53:43 by iarrar            #+#    #+#             */
/*   Updated: 2023/03/08 19:10:34 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	a;
	unsigned char	*dest;

	dest = (unsigned char *)str;
	i = 0;
	a = (unsigned char)c;
	if (c < 0)
		c = -c;
	while (i < n)
	{
		if (dest[i] == a)
			return ((void *)&dest[i]);
		else
			i++;
	}
	return (NULL);
}
