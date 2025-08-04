
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

// memset : set a block of memory to a value.
void *ft_memset(void *b, int c, size_t len)
{
	unsigned char *ptr = (unsigned char *)b;
	unsigned char ar = c;
	size_t i = 0;

	while (i < len)
	{
		ptr[i] = ar;
		i++;
	}

	return (b);
}
// bzero : be zero, mem!
void	ft_bzero(void *s, size_t n)
{
	unsigned char *ptr = (unsigned char *)s;
	size_t i = 0;

	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}

	return;
}

// memcpy : undefined if dst overlap with src
void *ft_memcpy(void * dst, const void * src, size_t n)
{
	size_t i = 0;
	unsigned char *ptr_dst = (unsigned char *)dst;
	const unsigned char *ptr_src = (const unsigned char *)src;

	while(i < n)
	{
		ptr_dst[i] = ptr_src[i];
		i++;
	}
	return (dst);
}

// memmove : Non-destructive manner in terms of the data stored in src
// How to check the memory overlapping? 
void *ft_memmove(void *dst, const void *src, size_t len)
{
	size_t i = 0;
	unsigned char *ptr_dst = (unsigned char *)dst;
	const unsigned char *ptr_src = (const unsigned char *)src;
	// go through the mem block to check overlapping
	// 1. fix dst, check src - str src is pre or overlapped with dst, or not.
	while (i < len)
	{
		if (ptr_src + i == ptr_dst)
		{
			//call function static backward_cp
			return (dst);
		}
		else
			i++;
	}
	i = 0;
	while (i < len)
	{
		if (ptr_src == ptr_dst + i)
		{
			//call function static forward_cp
			return (dst);
		}
		else
			i++;
	}
	return (dst);
}




#include <stdio.h>
int main(void) {
    printf("test out: %i \n", ft_isupper(EOF));
    return (0);
}