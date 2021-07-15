#include "../includes/ft_printf.h"

t_flags	ft_print_arg_char(t_flags flags, char *arg)
{
	if (flags.type == 'c' || flags.type == '%')
	{
		if (flags.prec > -1)
			arg[flags.prec] = 0;
		if (!flags.minus && !flags.zero)
			ft_print_width(flags, arg);
		if (!arg[0] && flags.type == 'c')
		{
			if (!flags.width)
				flags.width++;
			ft_putchar('\0');
		}
		else
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
		if (!arg[0] && flags.type == 'c')
		{
			if (!flags.width)
				flags.width++;
			ft_putchar('\0');
		}
		else
			ft_putstr(arg);
		if (flags.minus)
			ft_print_width(flags, arg);
	}
	return (flags);
}

t_flags	ft_print_num(char *arg, t_flags flags)
{
	if (ft_all_digits(arg))
		if (ft_atoi(arg) == 0 && (flags.prec == -2 || flags.prec == 0))
			arg[0] = 0;
	if (flags.prec >= 0)
		flags = ft_num_prec(arg, flags);
	else if (flags.zero)
		flags = ft_num_zero(arg, flags);
	else if (!flags.minus)
		ft_print_width(flags, arg);
	ft_putstr(arg);
	if (flags.minus)
		ft_print_width(flags, arg);
	if (flags.num && flags.prec != -1)
		flags.width += (flags.zero - ft_strlen(arg));
	return (flags);
}
