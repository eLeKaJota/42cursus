/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccifuent <ccifuent@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 17:09:53 by ccifuent          #+#    #+#             */
/*   Updated: 2021/07/14 20:16:04 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "includes/ft_printf.h"

int	main(void)
{

//	char *s1 = "Hola que tal";
//	int x = ft_printf("Puntero: [%p]\nString: [%s]\nChar: [%c]\nNúmero(d): [%d]\nNúmero(i): [%i]\nNúmero(u): [%u]\nHEX(445544): [%X]\nhex(445544): [%x]\nPercent: [%%]", s1, s1, 'h', -450, 5544, 542213206, 445544, 445544);
//	printf("\n\n");
//	int y = printf("Puntero: [%p]\nString: [%s]\nChar: [%c]\nNúmero(d): [%d]\nNúmero(i): [%i]\nNúmero(u): [%u]\nHEX(445544): [%X]\nhex(445544): [%x]\nPercent: [%%]", s1, s1, 'h', -450, 5544, 542213206, 445544, 445544);

	int x = ft_printf("%10.42u", -1);
	//system("leaks libftprintf.out");
	printf("\n");
	int y = printf("%10.42u", -1);
	printf("\nx: %d\n", x);
	printf("y: %d\n", y);
	printf("\n\n");
	return (0);
}