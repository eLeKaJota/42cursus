/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccifuent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 19:19:29 by ccifuent          #+#    #+#             */
/*   Updated: 2021/07/09 10:00:01 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		cont;

	dest = (char *) malloc(ft_strlen(s1) * sizeof(char) + 1);
	if (!dest)
		return (NULL);
	cont = 0;
	while (s1[cont])
	{
		dest[cont] = s1[cont];
		cont++;
	}
	dest[cont] = '\0';
	return (dest);
}
