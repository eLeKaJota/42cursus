#include "../includes/ft_printf.h"

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_print_zeros(t_flags flags, char *arg)
{
	int	r;
	int i;

	i = -1;
	r = flags.zero - ft_strlen(arg);
	while (++i < r)
		ft_putchar('0');
}

void	ft_print_width(t_flags flags, char *arg)
{
	int	r;
	int i;

	i = -1;
	r = flags.width - ft_strlen(arg);
	while (++i < r)
		ft_putchar(' ');
}

t_flags	ft_print_num(char *arg, t_flags flags)
{
	if (flags.prec >= 0 )
	{
		flags.zero = flags.prec;
		flags.width -= (flags.zero - ft_strlen(arg));
		if(!flags.minus)
			ft_print_width(flags, arg);
		ft_print_zeros(flags, arg);
	}
    else if (flags.zero)
	{
		flags.zero = flags.width;
		ft_print_zeros(flags, arg);
	}
    return (flags);
}

int	ft_print_arg(char *arg, char *fl)
{
	t_flags flags;

	flags = ft_init_flags();
	flags = ft_handle_flags(fl, flags);
	if (flags.type == 'd' || flags.type == 'i' || flags.type == 'u')
	{
		flags.num = 1;
		flags = ft_print_num(arg, flags);
	}
	if (flags.prec > -1 && !flags.num)
		arg[flags.prec] = 0;
	if (!flags.minus && !flags.zero && !flags.num)
		ft_print_width(flags, arg);
	ft_putstr(arg);
	if (flags.minus && !flags.num)
		ft_print_width(flags, arg);
	if (flags.minus && flags.num && flags.prec >= 0)
		ft_print_width(flags, arg);
	if (flags.width <= ft_strlen(arg))
		return (ft_strlen(arg) - (ft_strlen(fl) + 1));
	else
		return (flags.width - (ft_strlen(fl) + 1));
}
