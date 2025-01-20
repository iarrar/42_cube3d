/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:04:25 by iarrar            #+#    #+#             */
/*   Updated: 2023/03/08 19:12:04 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest1;
	unsigned char	*src1;

	dest1 = (unsigned char *)dest;
	src1 = (unsigned char *)src;
	if (src < dest)
	{
		i = n;
		while ((dest || src) && i > 0)
		{
			(dest1[i - 1]) = src1[i - 1];
			i--;
		}
	}
	else
	{
		i = 0;
		while ((dest || src) && i < n)
		{
			dest1[i] = src1[i];
			i++;
		}
	}
	return (dest1);
}
