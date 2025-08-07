#include <stddef.h>

static int	ft_isupper(int c)
{
	if (c <= 'Z' && c >= 'A')
		return (1);
	else
		return (0);
}
static int	ft_islower(int c)
{
	if (c <= 'z' && c >= 'a')
		return (1);
	else
		return (0);
}
int	ft_isalpha(int c)
{
	if (ft_isupper(c) && ft_islower(c))
		return (1);
	else
		return (0);
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
	if (ft_isalpha(c) && ft_isdigit(c))
		return (1);
	else
		return (0);
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
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

// memset : set a block of memory to a value.
void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;
	unsigned char	ar;
	size_t			i;

	ptr = (unsigned char *)b;
	ar = c;
	i = 0;
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
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
	return ;
}

// memcpy : undefined if dst overlap with src
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*ptr_dst;
	const unsigned char	*ptr_src = (const unsigned char *)src;

	i = 0;
	ptr_dst = (unsigned char *)dst;
	while (i < n)
	{
		ptr_dst[i] = ptr_src[i];
		i++;
	}
	return (dst);
}

// memmove : Non-destructive manner in terms of the data stored in src

static void	ft_backward_cp(unsigned char *dst, const unsigned char *src,
		size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		dst[len - i - 1] = src[len - i - 1];
		i++;
	}
}

static void	ft_forward_cp(unsigned char *dst, const unsigned char *src,
		size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
}
// check the overlap of memory
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*ptr_dst;
	const unsigned char	*ptr_src = (const unsigned char *)src;

	i = 0;
	ptr_dst = (unsigned char *)dst;
	/* check the positions of memory blocks
		*/
	if (ptr_dst == ptr_src || len == 0)
		return (dst);
	if (ptr_dst < ptr_src || ptr_src + len <= ptr_dst)
		ft_forward_cp(ptr_dst, ptr_src, len);
	else
		ft_backward_cp(ptr_dst, ptr_src, len);
	return (dst);
}

// copy the src string to dst. output the length of the trying-to-create,
ie.src size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	to_copy;

	srclen = 0;
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
		srclen++;
	return (srclen);
}
/* notice:
	1. returned length is the literal string length without the null terminator.
	2. if dst and src overlap, then the behavior is undefined.
	3. if len <= dstsize, then the user know the output is truncated.
*/

// same category as strlcpy; one of the target is to NULL-terminate dst,
which may not have it.size_t ft_strlcat(char *dst, const char *src,
	size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;

	dstlen = 0;
	srclen = 0;
	while (dstlen < dstsize && dst[dstlen])
		dstlen++;
	/*
	NULL termination - advantage: 1. we can evaluate
	the strlen easily; 2. protect from being
	accessing out of bound easily
	*/
	while (src[srclen] && dstsize > srclen + dstlen + 1)
	{
		dst[srclen + dstlen] = src[srclen];
		srclen++;
	}
	if (dstsize > dstlen)
		dst[srclen + dstlen] = '\0';
	while (src[srclen])
		srclen++;
	return (srclen + dstlen);
}

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 'a' + 'A';
	return (c);
}

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c = c - 'A' + 'a';
	return (c);
}

// treat the search range like a string
char	*ft_strchr(const char *s, int c)
{
	char	ch;

	ch = (char)c;
	while (*s)
	{
		if (*s == ch)
			return ((char *)s);
		s++;
	}
	if (ch == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strrchr(const char *s, int c)
{
	const char	*find = NULL;
	char		ch;

	ch = (char)c;
	while (*s)
	{
		if (*s == ch)
			find = s;
		s++;
	}
	if (ch == '\0')
		return ((char *)s);
	return ((char *)find);
}
// factor affecting corner case: size_t n == 0.
// 1. if size_t n == 0, it shouldn't compare at all.
// 2. if i == n, then also 0.
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n && s1[i] && s1[i] == s2[i])
		i++;
	// the latter two condition are classical combo - no need for another s2[i].
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

// search will not stop at '/0'.
// Always use unsigned char for raw memory functions.
void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char		*str = (const unsigned char *)s;
	unsigned char	uc;
	size_t			i;

	uc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == uc)
			return ((void *)(str + i));
		i++;
	}
	return (NULL);
}

// compare two strings, both are n-bytes long 
int ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char * str1 = (const unsigned char * ) s1;
	const unsigned char * str2 = (const unsigned char * ) s2;
	size_t i = 0;

	while ( i < n && str1[i] == str2[i])
		i++;
	if (i == n)
		return (0);
	return (str1[i] - str2[i]);
}

/*
	needle is null-terminated; haystack might not. the stop condition would be either
	condition is met : len characters are searched or met a '\0'
*/
char *	ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i = 0;
	size_t j = 0;
	size_t nlen = 0;

	if (needle[0] == '\0')
		return ((char *) haystack);

	while (needle[nlen])
        nlen++;

	while (i + nlen <= len && haystack[i])
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			while (haystack[i + j] == needle[j] &&  haystack[i + j] )
				j++;
			if (j == nlen)
				return ((char *)(haystack + i));
			if (haystack[i + j] == '\0')
				return (NULL);
		}
		i++;
	}
	return (NULL);
}
int	ft_atoi(const char *str)
{

}

#include <stdio.h>

int	main(void)
{
	printf("test out: %i \n", ft_isupper(EOF));
	return (0);
}
