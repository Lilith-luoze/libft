
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

static void ft_backward_cp(unsigned char *dst, const unsigned char *src, size_t len)
{
	size_t i = 0;
	while (i < len)
	{
		dst[len - i - 1] = src[len - i - 1];
		i++;
	}
}

static void ft_forward_cp(unsigned char *dst, const unsigned char *src, size_t len)
{
	size_t i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
}
// check the overlap of memory
void *ft_memmove(void *dst, const void *src, size_t len)
{
	size_t i = 0;
	unsigned char *ptr_dst = (unsigned char *)dst;
	const unsigned char *ptr_src = (const unsigned char *)src;
	/* check the positions of memory blocks 
	*/ 
	if (ptr_dst == ptr_src || len == 0)
		return dst;
	if(ptr_dst <  ptr_src || ptr_src + len <= ptr_dst )
		ft_forward_cp(ptr_dst, ptr_src, len);
	else
		ft_backward_cp(ptr_dst, ptr_src, len);
	return dst;
}

// copy the src string to dst. output the length of the trying-to-create, ie. src
size_t	ft_strlcpy(char * dst, const char * src, size_t dstsize)
{
	size_t srclen = 0;
	size_t to_copy;
	if (dstsize > 0)
		to_copy = dstsize - 1;
	else
		to_copy = 0;
	
	while (to_copy > 0 && src[srclen])
	{
		dst[srclen] = src[srclen];
		srclen++;
		to_copy--;
	}
	if (dstsize > 0)
		dst[srclen] = '\0';
	while (src[srclen])
		srclen ++;
	return (srclen);

}
/* notice: 
	1. returned length is the literal string length without the null terminator. 
	2. if dst and src overlap, then the behavior is undefined.
	3. if len <= dstsize, then the user know the output is truncated.
*/

size_t	ft_strlcat(char * dst, const char * src, size_t dstsize)
{
	size_t dstlen = 0;
	size_t srclen = 0;
	
	while (dst[dstlen])
		dstlen++;

	while (src[srclen] && dstsize > srclen + dstlen + 1 )
	{
		dst[srclen + dstlen] = src[srclen];
		srclen++;
	}
	if (dstsize > dstlen)
		dst[srclen + dstlen] = '\0';

	while (src[srclen])
		srclen ++;

	return (srclen + dstlen);
}

#include <stdio.h>
int main(void) {
    printf("test out: %i \n", ft_isupper(EOF));
    return (0);
}