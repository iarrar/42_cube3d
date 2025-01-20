/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:41:23 by iarrar            #+#    #+#             */
/*   Updated: 2023/08/21 14:18:15 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

int		ft_strlens(const char *str);
int		ft_putstr(char *s);
int		ft_putnbr(int n);
void	ft_putendl(char *s);
int		ft_putchar(char c);
int		ft_putnbru(unsigned int n);
int		ft_base(unsigned int n, char *str);
int		size_base(int n, int size);
int		ft_which_sign(va_list *args, char c);
int		ft_adresse(void *ptr);
int		ft_base_add(void *ptr, char *str);
int		ft_putnbru_base(unsigned int n, char *base);
int		ft_printf(const char *str, ...);
int		ft_countchar(const char *str, char c);
int		size_unsigned(unsigned int n, unsigned int base);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);

#endif
