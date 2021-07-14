/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccifuent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 19:55:31 by ccifuent          #+#    #+#             */
/*   Updated: 2021/07/12 10:18:23 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

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
