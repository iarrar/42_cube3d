/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbru_uns.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 18:24:33 by iarrar            #+#    #+#             */
/*   Updated: 2023/08/21 14:20:28 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbru_base(unsigned int n, char *base)
{
	char			c;
	unsigned int	i;
	unsigned int	s;

	s = n;
	i = (unsigned int)ft_strlens(base);
	if (n > i - 1)
	{
		c = base[(n % i)];
		n /= i;
		ft_putnbru_base(n, base);
		write(1, &c, 1);
	}
	else
	{
		c = base[n];
		write(1, &c, 1);
	}
	return (size_unsigned(s, ft_strlens(base)));
}
