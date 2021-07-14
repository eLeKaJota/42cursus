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
	int	i;

	i = -1;
	r = flags.zero - ft_strlen(arg);
	if (flags.zero && flags.prec == -1 && flags.minus)
		r = 0;
	while (++i < r)
		ft_putchar('0');
}

void	ft_print_width(t_flags flags, char *arg)
{
	int	r;
	int	i;

	i = -1;
	flags = ft_check_print_num(flags, arg);
	r = flags.width - ft_strlen(arg);
	if (!arg[0] && flags.width && flags.type == 'c')
		r--;
	if (flags.num && flags.zero && flags.prec == -2 && flags.minus)
		r--;
	while (++i < r)
		ft_putchar(' ');
}

t_flags	ft_print_arg_char(t_flags flags, char *arg)
{
	if (flags.type == 'c') {
		if (flags.prec > -1)
			arg[flags.prec] = 0;
		if (!flags.minus && !flags.zero)
			ft_print_width(flags, arg);
		if (!arg[0] && flags.type == 'c') {
			if (!flags.width)
				flags.width++;
			ft_putchar('\0');
		} else
			ft_putstr(arg);
		if (flags.minus)
			ft_print_width(flags, arg);
	}
	return (flags);
}

t_flags	ft_print_arg_str(t_flags flags, char *arg)
{
	if (flags.type == 's' || flags.type == 'p')
	{
		if (flags.prec == -2)
			flags.prec = 0;
		if (flags.prec > ft_strlen(arg))
			flags.prec = ft_strlen(arg);
		if (flags.prec > -1)
			arg[flags.prec] = 0;
		if (!flags.minus && !flags.zero)
			ft_print_width(flags, arg);
		if (!arg[0] && flags.type == 'c') {
			if (!flags.width)
				flags.width++;
			ft_putchar('\0');
		} else
			ft_putstr(arg);
		if (flags.minus)
			ft_print_width(flags, arg);
	}
	return (flags);
}

int	ft_print_arg(char *arg, char *fl)
{
	t_flags	flags;

	flags = ft_init_flags();
	flags = ft_handle_flags(fl, flags);
	flags = ft_print_arg_char(flags, arg);
	flags = ft_isnum(arg, flags);
	flags = ft_print_arg_str(flags, arg);
	/*if (flags.prec > -1 && !flags.num)
		arg[flags.prec] = 0;
	if (!flags.minus && !flags.zero && !flags.num)
		ft_print_width(flags, arg);
	ft_putstr(arg);
	if (flags.minus && !flags.num)
		ft_print_width(flags, arg);*/
	if (flags.prec > flags.width && flags.prec > ft_strlen(arg))
		return (flags.prec - (ft_strlen(fl) + 1));
	if (flags.width < ft_strlen(arg))
		return (ft_strlen(arg) - (ft_strlen(fl) + 1));
	else
		return (flags.width - (ft_strlen(fl) + 1));
}