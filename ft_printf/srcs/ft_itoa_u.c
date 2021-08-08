#include "../includes/ft_printf.h"

static void	ft_fill_m_u(char *ptr, unsigned int n, int a)
{
	unsigned int	k;

	k = n;
	ptr[a] = 0;
	a--;
	while (k >= 10)
	{
		ptr[a] = (k % 10) + '0';
		k = k / 10;
		a--;
	}
	ptr[a] = k + '0';
}

char	*ft_allocate_u(int a)
{
	char	*ptr;

	ptr = malloc(a + 1);
	if (!ptr)
		return (0);
	return (ptr);
}

char	*ft_itoa_u(unsigned int n)
{
	char			*ptr;
	int				a;
	unsigned int	k;

	a = 1;
	k = n;
	while (k >= 10)
	{
		k = k / 10;
		a++;
	}
	ptr = ft_allocate_u(n);
	if (!ptr)
		return (0);
	ft_fill_m_u(ptr, n, a);
	return (ptr);
}
