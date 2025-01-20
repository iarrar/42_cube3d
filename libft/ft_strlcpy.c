/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:41:08 by iarrar            #+#    #+#             */
/*   Updated: 2023/03/01 11:13:32 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	res;

	i = 0;
	res = ft_strlen(src);
	while ((src[i] && i < size - 1 && size >= 1))
	{
		dest[i] = src[i];
		i++;
	}
	if (size >= 1)
		dest[i] = '\0';
	return (res);
}
