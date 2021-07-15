#include "../includes/ft_printf.h"

t_flags	ft_check_print_num(t_flags flags, char *a)
{
	if (flags.width && !flags.zero && flags.prec == -1)
	{
		if (ft_atoi(a) < 0)
			flags.width++;
	}
	else if (flags.zero < ft_strlen(a) && flags.prec >= 0)
	{
		flags.width += flags.zero - ft_strlen(a);
		if (ft_atoi(a) < 0)
			flags.width++;
	}
	else if (flags.zero < ft_strlen(a))
	{
		flags.width++;
		flags.width += flags.zero - ft_strlen(a);
	}
	if (flags.minus && (a[0] == '0' && ft_atoi(a) != 0))
		flags.width--;
	if (ft_atoi(a) < 0)
		flags.width--;
	if (flags.type == 'u' && flags.prec >= 10 && flags.prec == ft_strlen(a))
		flags.width++;
	return (flags);
}

t_flags	ft_num_prec(char *arg, t_flags flags)
{
	flags.zero = flags.prec;
	flags.width -= (flags.zero - ft_strlen(arg));
	if (!flags.minus)
		ft_print_width(flags, arg);
	if (ft_atoi(arg) < 0 && flags.zero >= ft_strlen(arg) && flags.type != 'u')
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
	if (ft_atoi(arg) < 0 && flags.zero >= ft_strlen(arg) && flags.type != 'u')
	{
		arg[0] = '0';
		ft_putchar('-');
		flags.zero--;
	}
	ft_print_zeros(flags, arg);
	return (flags);
}

int	ft_all_digits(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]) && arg[i] != '-')
			return (0);
		i++;
	}
	return (1);
}

t_flags	ft_isnum(char *arg, t_flags flags)
{
	if (flags.type == 'd' || flags.type == 'i' || flags.type == 'u')
	{
		flags.num = 1;
		flags = ft_print_num(arg, flags);
	}
	if (flags.type == 'x' || flags.type == 'X')
	{
		flags.num = 1;
		flags = ft_print_num(arg, flags);
	}
	return (flags);
}
