/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccifuent <ccifuent@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 18:26:30 by ccifuent          #+#    #+#             */
/*   Updated: 2021/08/23 10:13:52 by ccifuent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include <signal.h>
#include <unistd.h>
#include <stdio.h>

int	ft_print_origin(siginfo_t *info)
{
	ft_printf("[Enviado desde: %d]\n", info->si_pid);
	return (0);
}

void	ft_get_binary(int s, siginfo_t *info, void *context)
{
	static int	i;
	static int	c;
	static int	r;

	if (!r)
	{
		i = 0;
		c = 255;
		write(1, "\n\n---> ", 7);
	}
	r++;
	if (s == SIGUSR1)
		c = c | 128 >> i;
	if (s == SIGUSR2)
		c = c ^ 128 >> i;
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		if (c == '\n')
			r = ft_print_origin(info);
		i = 0;
		c = 255;
	}
}

int	main(void)
{
	pid_t				pid;
	sigset_t			set0;
	sigset_t			set1;
	struct sigaction	act0;
	struct sigaction	act1;

	pid = getpid();
	ft_printf("%d\n", pid);
	sigemptyset(&set0);
	sigaddset(&set0, SIGUSR2);
	act0.sa_sigaction = ft_get_binary;
	act0.sa_mask = set0;
	act0.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR2, &act0, NULL);
	sigemptyset(&set1);
	sigaddset(&set1, SIGUSR1);
	act1.sa_sigaction = ft_get_binary;
	act1.sa_mask = set1;
	act1.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act1, NULL);
	while (1)
		pause();
	return (0);
}
