/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <event@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 10:33:31 by artmarti          #+#    #+#             */
/*   Updated: 2024/02/22 13:56:51 by event            ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# define BUFFER_SIZE 42 

char	*ft_substr2(char const *s, unsigned int start, size_t len);
int		ft_strlen2(const char *str);
char	*ft_strchr2(const char *s, int i);
char	*ft_strdup2(const char *s);
char	*ft_strjoin2(char const *s1, char const *s2);
char	*get_next_line(int fd);

#endif
