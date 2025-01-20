/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 18:22:59 by iarrar            #+#    #+#             */
/*   Updated: 2023/08/21 14:20:56 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	size_base(int n, int base)
{
	int	i;
	int	div;

	i = 0;
	div = n;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		div = -n;
		i++;
	}
	if (div < base)
		return (i + 1);
	while (div >= base)
	{
		div = div / base;
		i++;
	}
	return (i + 1);
}
