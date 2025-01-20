/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:41:01 by iarrar            #+#    #+#             */
/*   Updated: 2023/03/11 18:37:51 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *lit, size_t len)
{
	size_t	i;
	char	*big1;

	big1 = (char *)big;
	i = 0;
	if (!big && !lit)
		return (NULL);
	if (!lit[0])
		return (big1);
	if (ft_strlen(lit) > len)
		return (NULL);
	while (big[i] && i <= (len - ft_strlen(lit)))
	{
		if (!ft_strncmp(&big[i], lit, ft_strlen(lit)))
			return (&big1[i]);
		else
			i++;
	}
	return (NULL);
}
