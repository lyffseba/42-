/*HEADER*/

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	digit;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	digit = nb % 10 + '0';
	write(1, &digit, 1);
}
/*
int	main(void)
{
	ft_putnbr(42);
	write(1, "\n", 1);
	ft_putnbr(13);
	write(1, "\n", 1);
	ft_putnbr(1232130);
	write(1, "\n", 1);
	return (0);
}
*/
