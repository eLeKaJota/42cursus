/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccifuent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 16:34:16 by ccifuent          #+#    #+#             */
/*   Updated: 2021/07/15 17:08:51 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdint.h>

typedef struct s_flags
{
	int		width;
	int		prec;
	int		zero;
	int		minus;
	int		dot;
	int		num;
	char	type;
}		t_flags;

int		ft_printf(const char *cpy, ...);
void	ft_putchar(int c);
void	ft_putstr(char *str);
int		ft_print_arg(char *arg, char *fl);
char	*ft_alloc_char(char c);
int		ft_count_hex(uintptr_t n);
char	*ft_alloc_upperx(uintptr_t n);
char	*ft_alloc_hex(uintptr_t n);
char	*ft_alloc_ptr(uintptr_t n);
void	ft_clean(char *fl, char *arg);
char	*ft_flags_info(char *str);
char	ft_check_type(char c);
t_flags	ft_init_flags(void);
t_flags	ft_handle_flags(char *fl, t_flags flags);
void	ft_print_width(t_flags flags, char *arg);
void	ft_print_zeros(t_flags flags, char *arg);
int		ft_get_width(char *str);
t_flags	ft_check_print_num(t_flags flags, char *arg);
t_flags	ft_num_prec(char *arg, t_flags flags);
t_flags	ft_num_zero(char *arg, t_flags flags);
t_flags	ft_print_num(char *arg, t_flags flags);
t_flags	ft_isnum(char *arg, t_flags flags);
char	*ft_itoa_u(unsigned int n);
t_flags	ft_print_arg_char(t_flags flags, char *arg);
t_flags	ft_print_arg_str(t_flags flags, char *arg);
t_flags	ft_print_num(char *arg, t_flags flags);
int	ft_all_digits(char *arg);

#endif
