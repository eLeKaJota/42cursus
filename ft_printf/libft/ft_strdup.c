/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccifuent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 19:19:29 by ccifuent          #+#    #+#             */
/*   Updated: 2021/07/14 20:10:05 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		cont;

	if (!s1)
	{
		dest = (char *) malloc((6 * sizeof(char)) + 1);
		if (!dest)
			return (NULL);
		dest[0] = '(';
		dest[1] = 'n';
		dest[2] = 'u';
		dest[3] = 'l';
		dest[4] = 'l';
		dest[5] = ')';
		dest[6] = 0;
		return (dest);
	}
	dest = (char *) malloc(ft_strlen(s1) * sizeof(char) + 1);
	if (!dest)
		return (NULL);
	cont = -1;
	while (s1[++cont])
		dest[cont] = s1[cont];
	dest[cont] = '\0';
	return (dest);
}
