#include "../includes/ft_printf.h"

t_flags	ft_init_flags(void)
{
	t_flags	flags;

	flags.width = 0;
	flags.prec = -1;
	flags.zero = 0;
	flags.minus = 0;
	flags.dot = 0;
	flags.num = 0;
	return (flags);
}

int	ft_get_width(char *str)
{
	int		i;
	char	*n;
	int		res;

	i = 0;
	while (ft_isdigit(str[i]))
		i++;
	if (i == 0)
		return (0);
	n = malloc((i + 1) * sizeof(char));
	i = -1;
	while (ft_isdigit(str[++i]))
		n[i] = str[i];
	n[i] = 0;
	res = ft_atoi(n);
	free(n);
	return (res);
}

t_flags	ft_handle_flags(char *fl, t_flags flags)
{
	int	i;

	i = -1;
	flags.type = fl[ft_strlen(fl) - 1];
	while (!ft_check_type(fl[++i]))
	{
		if (fl[i] == '0')
			flags.zero = 1;
		if (fl[i] == '-')
			flags.minus = 1;
		while (ft_isdigit(fl[i]) && fl[i] != '0')
		{
			if (!flags.width)
				flags.width = ft_get_width(&fl[i]);
			i++;
		}
		if (fl[i] == '.')
		{
			flags.prec = -2;
			while (ft_isdigit(fl[++i]))
				if (flags.prec < 0)
					flags.prec = ft_get_width(&fl[i]);
		}
	}
	return (flags);
}
