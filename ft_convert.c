#include "libft.h"


// integer overflow is undefined behavior
int	ft_atoi(const char *str)
{
	int digit;
	int result;
	int sign;
	result = 0;
	sign = 1;

	if (!str)
		return (0);
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		digit = *str - '0';
		result = result * 10 + digit;
		str++;
	}
	return (result * sign);
}

// count the length of int.
static size_t ft_itoa_len(int nbr)
{
	size_t len;
	len = 0;
	if (nbr == 0)
		len++; /*for jump over the while loop*/
	if (nbr < 0)
		len++; /*for '-'*/
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

/*itoa return a string that can be freed*/
char	*ft_itoa(int n)
{
	char *str;
	size_t len;
	size_t i;
	i = 0;
	str = NULL;
	len = ft_itoa_len(n);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (n < 0)
		str[0] = '-';
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		if (n < 0)
			str[len - 1 - i] = '0' - n % 10;
		else
			str[len - 1 - i] = '0' + n % 10;
		i++;
		n = n / 10;
	}
	return (str);
}