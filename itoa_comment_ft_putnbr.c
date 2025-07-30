#include <unistd.h>
// int to char
void ft_putnbr(int nb)
{
    int dgt;
    // char dgt_char;
    char str[10];
    int i;
    int ori_nbr;

    if (nb == 0)
        write(1,"0", 1);
    else 
        ori_nbr = nb;
        // init the char array
        i = 0;
        while (i < 10)
        {
            str[i] = '\0';
            i++;
        }
        // get the array of char of our number
        i = 0;
        if (nb < 0)
            nb = -nb;
        while(nb != 0)
        {
            dgt = nb % 10;
            if (dgt < 0)
                dgt = -dgt;
            nb = nb / 10; 
            str[i] = '0' + dgt;
            i++;
        }
        //print array reversely. we've got i digit 
        if (ori_nbr < 0)
            write(1 , "-", 1);
        while (i > 0)
        {
            write(1 , &str[i-1] , 1);
            i--;
        }
}

int	main(void)
{
	ft_putnbr(0);
	return (0);
}