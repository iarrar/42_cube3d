/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:51:56 by iarrar            #+#    #+#             */
/*   Updated: 2023/03/08 10:37:29 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_power_ten(int n)
{
	int	i;
	int	res;

	res = n;
	i = 0;
	if (n < 0)
		res = -n;
	else if (n < 10)
		return (1);
	while (res >= 10)
	{
		res = res / 10;
		i++;
	}
	return (i);
}

static char	*ft_convert(int n)
{
	int		res;
	int		mod;
	int		i;
	char	*str;

	i = 0;
	if (n < 0)
		res = -n;
	if (n >= 0)
		res = n;
	str = ft_calloc(sizeof (char), ft_power_ten(n) + 1);
	if (!str)
		return (NULL);
	while (res >= 10)
	{
		mod = res % 10;
		res = res / 10;
		str[i] = mod + 48;
		i++;
	}
	str[i] = res + 48;
	str[i + 1] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	size_t	i;
	size_t	j;
	char	*str;
	char	*inv;

	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	inv = ft_convert(n);
	if (!inv)
		return (NULL);
	j = ft_strlen(inv);
	if (n < 0)
	{
		str = ft_calloc(sizeof(char), (j + 2));
		str[i] = '-';
		i++;
	}
	else if (n >= 0)
		str = ft_calloc(sizeof(char), (j + 1));
	while (j >= 1)
		str[i++] = inv[j-- - 1];
	str[i] = '\0';
	return (str);
}
