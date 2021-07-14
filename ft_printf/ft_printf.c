#include "includes/ft_printf.h"

char	*ft_get_arg(va_list args, char *fl)
{
	char	*arg;
	char	type;
	int		t;

	t = ft_strlen(fl) - 1;
	type = fl[t];
	if (type == 'd' || type == 'i')
		arg = ft_itoa(va_arg(args, int));
	if (type == 'u')
		arg = ft_itoa(va_arg(args, unsigned int));
	if (type == 's')
		arg = ft_strdup(va_arg(args, char *));
	if (type == '%')
		arg = ft_strdup("%");
	if (type == 'c')
		arg = ft_alloc_char(va_arg(args, int));
	if (type == 'x' || type == 'X')
		arg = ft_alloc_hex(va_arg(args, unsigned int));
	if (type == 'p')
		arg = ft_alloc_ptr(va_arg(args, uintptr_t));
	return (arg);
}

int	ft_handle_percent(va_list args, char *str)
{
	int		length;
	char	*fl;
	char	*arg;

	length = 0;
	fl = ft_flags_info(str);
	arg = ft_get_arg(args, fl);
	length += ft_print_arg(arg, fl);
	ft_clean(fl, arg);
	return (length);
}

int	ft_printf(const char *cpy, ...)
{
	va_list	args;
	int		i;
	int		length;
	char	*str;

	i = -1;
	length = 0;
	str = ft_strdup(cpy);
	va_start(args, cpy);
	while (str[++i] != 0)
	{
		if (str[i] == '%')
		{
			length += ft_handle_percent(args, &str[++i]);
			while (!ft_check_type(str[i]))
				i++;
		}
		else
			ft_putchar(str[i]);
	}
	va_end(args);

	i = ft_strlen(cpy) + length;
	free(str);
	return (i);
}
