#include <unistd.h>

int	ft_itoa_array(int nb, char *str)
{
	int	i;
	int	dgt;

	i = 0;
	if (nb < 0)
		nb = -nb;
	while (nb != 0)
	{
		dgt = nb % 10;
		if (dgt < 0)
			dgt = -dgt;
		nb = nb / 10;
		str[i] = '0' + dgt;
		i++;
	}
	return (i);
}

void	ft_putnbr(int nb)
{
	char	str[10];
	int		i;
	int		ori_nbr;

	if (nb == 0)
		write(1, "0", 1);
	else
		ori_nbr = nb;
	i = 0;
	while (i < 10)
	{
		str[i] = '\0';
		i++;
	}
	i = ft_itoa_array(nb, str);
	if (ori_nbr < 0)
		write(1, "-", 1);
	while (i > 0)
	{
		write(1, &str[i - 1], 1);
		i--;
	}
}

int	main(void)
{
	ft_putnbr(-2147483648);
	return (0);
}
