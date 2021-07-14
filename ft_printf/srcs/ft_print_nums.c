#include "../includes/ft_printf.h"

t_flags	ft_check_print_num(t_flags flags, char *arg)
{
	if (flags.num) {
		if (flags.width && !flags.zero && flags.prec == -1) {
			if (ft_atoi(arg) < 0)
				flags.width++;
		} else if (flags.zero < ft_strlen(arg) && flags.prec >= 0) {
			flags.width += flags.zero - ft_strlen(arg);
			if (ft_atoi(arg) < 0)
				flags.width++;
		} else if (flags.zero < ft_strlen(arg)) {
			flags.width++;
			flags.width += flags.zero - ft_strlen(arg);
		}
		if (flags.minus && (arg[0] == '0' && ft_atoi(arg) != 0))
			flags.width--;
		if (ft_atoi(arg) < 0)
			flags.width--;
	}
	return (flags);
}

t_flags	ft_num_prec(char *arg, t_flags flags)
{
	flags.zero = flags.prec;
	flags.width -= (flags.zero - ft_strlen(arg));
	if (!flags.minus)
		ft_print_width(flags, arg);
	if (ft_atoi(arg) < 0 && flags.zero >= ft_strlen(arg))
	{
		arg[0] = '0';
		ft_putchar('-');
		flags.prec++;
	}
	ft_print_zeros(flags, arg);
	return (flags);
}

t_flags	ft_num_zero(char *arg, t_flags flags)
{
	flags.zero = flags.width;
	if (flags.minus)
		flags.zero = 0;
	if (ft_atoi(arg) < 0 && flags.zero >= ft_strlen(arg))
	{
		arg[0] = '0';
		ft_putchar('-');
		flags.zero--;
	}
	ft_print_zeros(flags, arg);
	return (flags);
}

t_flags	ft_print_num(char *arg, t_flags flags)
{
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

t_flags	ft_isnum(char *arg, t_flags flags)
{
	if (flags.type == 'd' || flags.type == 'i' || flags.type == 'u')
	{
		flags.num = 1;
		flags = ft_print_num(arg, flags);
	}
	return (flags);
}
