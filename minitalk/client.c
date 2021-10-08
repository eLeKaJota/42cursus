/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccifuent <ccifuent@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 17:46:55 by ccifuent          #+#    #+#             */
/*   Updated: 2021/08/23 12:29:16 by ccifuent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include <signal.h>
#include <unistd.h>

void	ft_conv_binary(char c, int pid)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		if (128 & c << i)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(80);
	}
}

void	ft_send_string(int pid, char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		ft_conv_binary(s[i], pid);
	ft_conv_binary('\n', pid);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("Número incorrecto de argumentos");
		return (0);
	}
	ft_send_string(ft_atoi(argv[1]), argv[2]);
	return (0);
}
