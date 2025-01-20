/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbru_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:14:43 by iarrar            #+#    #+#             */
/*   Updated: 2023/08/21 14:09:03 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	size_unsigned(unsigned int n, unsigned int base)
{
	int				i;
	unsigned int	div;

	i = 0;
	div = n;
	if (div < base)
		return (i + 1);
	while (div >= base)
	{
		div = div / base;
		i++;
	}
	return (i + 1);
}

int	ft_putnbru(unsigned int n)
{
	char			c;
	unsigned int	s;

	s = n;
	if (n > 9)
	{
		c = (n % 10) + '0';
		n /= 10;
		ft_putnbru(n);
		write(1, &c, 1);
	}
	else
	{
		c = n + '0';
		write(1, &c, 1);
	}
	return (size_unsigned(s, 10));
}
