/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 20:08:10 by iarrar            #+#    #+#             */
/*   Updated: 2023/03/06 10:57:03 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;
	size_t	index;

	index = 0;
	i = ft_strlen(s);
	if (!s)
		return (NULL);
	if (start > i - 1 || s[0] == '\0')
		return (ft_strdup(""));
	if (len <= i - start)
		dest = ft_calloc(len + 1, sizeof(char));
	if (len > i - start)
		dest = ft_calloc(i - start + 1, sizeof(char));
	if (!dest)
		return (NULL);
	while (index < len && s[index + start])
	{
		dest[index] = s[start + index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}
