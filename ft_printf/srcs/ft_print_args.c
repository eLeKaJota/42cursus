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
	if (flags.num && flags.prec < 0 && ft_atoi(arg) >= 0 && flags.plus)
		r--;
	while (++i < r)
		ft_putchar('0');
}

void	ft_print_width(t_flags flags, char *arg)
{
	int	r;
	int	i;

	i = -1;
	if (flags.num)
		flags = ft_check_print_num(flags, arg);
	r = flags.width - ft_strlen(arg);
	if (!arg[0] && flags.width && flags.type == 'c')
		r--;
	if (flags.num && flags.zero && flags.prec == -2 && flags.minus)
		r--;
	if (flags.num && ft_atoi(arg) >= 0 && flags.plus)
		r--;
	while (++i < r)
		ft_putchar(' ');
}

int	ft_print_arg(char *arg, char *fl)
{
	t_flags	flags;
	int		plus;

	plus = 0;
	flags = ft_init_flags();
	flags = ft_handle_flags(fl, flags);
	flags = ft_print_arg_char(flags, arg);
	flags = ft_isnum(arg, flags);
	flags = ft_print_arg_str(flags, arg);
	if (flags.num && flags.plus && ft_atoi(arg) >= 0)
		plus++;
	if (flags.prec > flags.width && flags.prec > ft_strlen(arg))
		return (flags.prec - (ft_strlen(fl) + 1) + plus);
	if (flags.width < ft_strlen(arg))
		return (ft_strlen(arg) - (ft_strlen(fl) + 1) + plus);
	else
		return (flags.width - (ft_strlen(fl) + 1));
}
