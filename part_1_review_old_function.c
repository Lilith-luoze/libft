
static int ft_isupper(int c)
{
    if (c <= 'Z' && c >= 'A')
        return (1);
    else 
        return (0);
}
static int ft_islower(int c)
{
    if (c <= 'z' && c >= 'a')
        return (1);
    else 
        return (0);
}
int	ft_isalpha(int c)
{
	if (ft_isupper(c) && ft_islower(c) )
		return(1);
	else
		return(0);
}
int	ft_isdigit(int c)
{
	if (c <= '9' && c >= '0')
		return (1);
	else 
		return (0);
}

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) && ft_isdigit(c) )
		return(1);
	else
		return(0);
}
int	ft_isascii(int c)
{
	if (c <= 127 && c >= 0)
		return (1);
	else 
		return (0);
}

int	ft_isprint(int c)
{
	if (c <= 126 && c >= 32)
		return (1);
	else 
		return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t i;
    i = 0;
    while(s[i])
        i++;
    return (i);
}







#include <stdio.h>
int main(void) {
    printf("test out: %i \n", ft_isupper(EOF));
    return (0);
}