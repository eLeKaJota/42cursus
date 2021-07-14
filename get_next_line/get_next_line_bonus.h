/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccifuent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 18:17:58 by ccifuent          #+#    #+#             */
/*   Updated: 2021/07/03 09:49:56 by ccifuent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# define FD_I 4096
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
int		get_next_line(int fd, char **line);
char	*ft_strjoin(char *s1, char const *s2);
int		ft_strlen(const char *s);
int		ft_check_n(char *str);
#endif
