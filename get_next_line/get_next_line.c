/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*   By: ccifuent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 19:26:05 by ccifuent          #+#    #+#             */
/*   Updated: 2021/07/02 10:57:53 by ccifuent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
char	*ft_get_cache(char *cache)
{
	int		i;
	int		j;
	char	*r;

	i = 0;
	j = 0;
	if (!(ft_check_n(cache)) && cache)
	{
		free(cache);
		return (0);
	}
	if (!cache)
		return (0);
	while (cache[i] && (cache[i] != '\n'))
		i++;
	r = malloc((ft_strlen(cache) - i) + 1);
	if (!r)
		return (0);
	if (cache[i] != 0)
		i++;
	while (cache[i])
		r[j++] = cache[i++];
	r[j] = 0;
	free(cache);
	return (r);
}

char	*ft_get_line(char *cache)
{
	int		i;
	char	*r;

	i = 0;
	while (cache[i] && cache[i] != '\n')
		i++;
	r = malloc(i + 1);
	if (!r)
		return (0);
	i = -1;
	while (cache[++i] && cache[i] != '\n')
		r[i] = cache[i];
	r[i] = 0;
	return (r);
}

char	*ft_alloc(int buffer_size)
{
	char	*cch;

	cch = malloc(buffer_size + 1);
	if (!cch)
		return (0);
	return (cch);
}

int	get_next_line(int fd, char **line)
{
	static char	*cache;
	int			res;
	char		*buffer;

	res = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	buffer = ft_alloc(BUFFER_SIZE);
	while (!ft_check_n(cache) && res > 0)
	{
		res = read(fd, buffer, BUFFER_SIZE);
		if (res == -1)
		{
			free(buffer);
			return (-1);
		}
		buffer[res] = 0;
		cache = ft_strjoin(cache, buffer);
	}
	*line = ft_get_line(cache);
	cache = ft_get_cache(cache);
	free(buffer);
	if (res == 0)
		return (0);
	return (1);
}

int	main(void)
{
	int fd = open("file",O_RDONLY);
	char	*line;
	int	x;

	x = get_next_line(fd, &line);
	printf("%d - %s\n", x, line);
	x = get_next_line(fd, &line);
	printf("%d - %s\n", x, line);
	x = get_next_line(fd, &line);
	printf("%d - %s\n", x, line);
	x = get_next_line(fd, &line);
	printf("%d - %s\n", x, line);
	x = get_next_line(fd, &line);
	printf("%d - %s\n", x, line);
	x = get_next_line(fd, &line);
	printf("%d - %s\n", x, line);
	close(fd);
	return (0);
}
