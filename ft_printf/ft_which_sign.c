/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_which_sign.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 18:09:49 by iarrar            #+#    #+#             */
/*   Updated: 2023/08/21 14:17:08 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_which_sign(va_list *args, char c)
{
	int	i;

	i = 0;
	if (c == 'c')
		i = ft_putchar(va_arg(*args, int));
	if (c == 's')
		i = ft_putstr(va_arg(*args, char *));
	if (c == 'p')
		i = ft_adresse(va_arg(*args, void *));
	if (c == 'd')
		i = ft_putnbr(va_arg(*args, int));
	if (c == 'i')
		i = ft_putnbr(va_arg(*args, int));
	if (c == 'u')
		i = ft_putnbru(va_arg(*args, unsigned int));
	if (c == 'x')
		i = ft_putnbru_base(va_arg(*args, int), "0123456789abcdef");
	if (c == 'X')
		i = ft_putnbru_base(va_arg(*args, int), "0123456789ABCDEF");
	if (c == '%')
		i = ft_putchar('%');
	return (i);
}
