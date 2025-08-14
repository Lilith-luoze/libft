#include "libft.h"

void ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
void ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return;
	write(fd, s, ft_strlen(s));
}

void ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return;
	write(fd, s, ft_strlen(s));
	write(fd, "\n",1);
}

static void ft_putnbr_rec(long nl, int fd)
{
	char ch;
    if (nl >= 10)
        ft_putnbr_rec(nl / 10, fd);
    ch = nl % 10 + '0';
    write(fd,  &ch, 1);
}

void ft_putnbr_fd(int n, int fd)
{
	long nl;
	nl = n;
	if (nl < 0)    
    {
        write(fd, "-", 1);
        nl = -nl;
    }     
	ft_putnbr_rec(nl , fd);
}