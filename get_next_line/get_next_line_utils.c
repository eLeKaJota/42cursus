/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccifuent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 16:31:49 by ccifuent          #+#    #+#             */
/*   Updated: 2021/07/02 12:14:34 by ccifuent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_check_n(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (0);
	while (str[++i])
	{
		if (str[i] == '\n' || str[i] == 0)
		{
			return (1);
		}
	}
	return (0);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*tmp_dst;
	unsigned char	*tmp_src;

	if (!dst && !src)
		return (0);
	tmp_dst = (unsigned char *) dst;
	tmp_src = (unsigned char *) src;
	i = -1;
	while (++i < n)
		tmp_dst[i] = tmp_src[i];
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*tmp_dst;
	char	*tmp_src;

	tmp_dst = (char *)dst;
	tmp_src = (char *)src;
	if (tmp_dst > tmp_src)
	{
		while (len--)
			tmp_dst[len] = tmp_src[len];
	}
	else if (tmp_dst < tmp_src)
		ft_memcpy(dst, src, len);
	return (dst);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*ptr;
	int		i1;
	int		i2;
	int		it;

	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = 0;
	}
	i1 = ft_strlen(s1);
	i2 = ft_strlen(s2);
	it = i1 + i2 + 1;
	ptr = malloc(it);
	if (ptr == 0)
		return (0);
	ft_memmove(ptr, s1, i1);
	ft_memmove(ptr + i1, s2, i2);
	ptr[it - 1] = 0;
	free((char *)s1);
	return (ptr);
}
