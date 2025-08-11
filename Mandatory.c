#include "libft.h"



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
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

// memset : set a block of memory to bytes of value.
void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *ptr;
	unsigned char ar;
	size_t i;

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
// bzero : all be zero, bytes!
void	ft_bzero(void *s, size_t n)
{
	unsigned char *ptr;
	size_t i;

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
	size_t i;
	unsigned char *ptr_dst;
	const unsigned char *ptr_src = (const unsigned char *)src;

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
	size_t i;

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
	size_t i;

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
	size_t i;
	unsigned char *ptr_dst;
	const unsigned char *ptr_src = (const unsigned char *)src;

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
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t srclen;
	size_t to_copy;

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

// same category as strlcpy; one of the target is to NULL-terminate dst,which may not have it.

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t dstlen;
	size_t srclen;

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
	char ch;

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
	const char *find = NULL;
	char ch;

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
	size_t i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n && s1[i] && s1[i] == s2[i])
		i++;
	// the latter two condition are classical combo	- no need for another s2[i].
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

// search will not stop at '/0'.
// Always use unsigned char for raw memory functions.
void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char *str = (const unsigned char *)s;
	unsigned char uc;
	size_t i;

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
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *str1 = (const unsigned char *)s1;
	const unsigned char *str2 = (const unsigned char *)s2;
	size_t i = 0;

	while (i < n && str1[i] == str2[i])
		i++;
	if (i == n)
		return (0);
	return (str1[i] - str2[i]);
}

/*
	needle is null-terminated; haystack might not. the stop condition would be either
	condition is met : len characters are searched or met a '\0'
*/
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i = 0;
	size_t j = 0;
	size_t nlen = 0;

	if (needle[0] == '\0')
		return ((char *)haystack);

	while (needle[nlen])
		nlen++;

	while (i + nlen <= len && haystack[i])
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			while (haystack[i + j] == needle[j] && haystack[i + j])
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
// continuously allocate memory and set them to bytes of zero

// how to detect overflow
void	*ft_calloc(size_t count, size_t size)
{
	void *ptr = NULL;
	size_t bf = 0;

	if (size && count > SIZE_MAX / size)
		return (NULL);
	bf = count * size; // overflow possibility after multiplicatio

	if (bf == 0)
		bf = 1; // super smart

	ptr = malloc(bf);
	if (ptr == NULL)
		return (NULL);

	ft_bzero(ptr, bf); // call your friend.
	return (ptr);
}

char	*ft_strdup(const char *s)
{
	// malloc
	char *dup;
	size_t i;
	i = 0;
	dup = malloc((ft_strlen(s) + 1) * sizeof(*s));
	if (dup == NULL)
		return (NULL);
	// dupicate
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

// from now on all from Part 2 Additional functions. they have almost similar functioanlity but all(?) use malloc


char	*ft_strjoin(char const *s1, char const *s2)
{
	char *result;
	size_t i = 0;
	size_t j = 0;
	result = NULL;
	if (!s1 || !s2)
		return (NULL);

	result = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(*s1));
	if (!result)
		return (NULL);
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		result[i] = s2[j];
		j++;
		i++;
	}
	return (result);
}

char	*ft_strtrim(char const *s1, char const *set)
/*temp good; check edge again*/
{
	size_t start;
	size_t len;
	char *out;
	out = NULL;
	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	if (!len)
		return (ft_calloc(1, 1));
	start = 0;
	while (s1[start] && ft_strchr(set, (int)s1[start]))
		start++; /*inclusive start index*/
	while (len > start && ft_strchr(set, (int)s1[len - 1]))
		len--;
	if (start <= len)
		out = ft_calloc(len - start + 1, sizeof(*s1));
	else
		return (ft_calloc(1, 1));
	if (!out)
		return (NULL);
	ft_strlcpy(out, s1 + start, len - start + 1);
	return (out);
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char *sub; /*malloc len of len
		+ 1 ; use both len and null terminator as stop sign*/
	size_t i = 0;
	size_t len_s;
	if (s == NULL)
		return (NULL);
	len_s = ft_strlen(s);
	/* compare the start position and strlen of s */
	if (start >= len_s)
		return (ft_strdup(""));

	if (len_s - start < len) /*avoid overallocation*/
		len = len_s - start;
	sub = ft_calloc(len + 1, sizeof(*s)); /*reuse your piece of code*/
	if (sub == NULL)
		return (NULL);
	while (i < len)
	{
		sub[i] = s[i + start];
		i++;
	}
	return (sub);
}

static size_t ft_word_count(char const *s, char c)
{
	size_t num_words = 0;
	size_t i;
	int met_delim = 1;
	i = 0;
	while (s[i])
	{
		if(s[i] != c && met_delim == 1)
		{
			num_words++;
			met_delim = 0;
		}
		else if (s[i] == c)
			met_delim = 1;
		i++;
	}
	return (num_words);
}
static void *ft_free_split(void **ptr, size_t n)
{
	size_t offset;
	offset = 0;
	while (offset < n)
	{
		free(ptr[offset]);
		offset++;
	}
	free(ptr);
	return (NULL);
}
/*only count effective words*/
//funtion free before if one malloc failed
static size_t ft_wordlen(char const *s, char c)
{
	size_t len = 0;
	while(s[len] && s[len] != c)
		len++;
	return (len);
}
 static void ft_init_vars(size_t *num_words, size_t *i, size_t *k, char ***ptr)
{
	*k = 0;
	*i = 0;
	*ptr = NULL;
	*num_words = 0;
}

char	**ft_split(char const *s, char c)
{
	size_t num_words;
	size_t i;
	size_t k;
	size_t len;
	char **ptr;
	if (!s) 
		return (NULL);
	ft_init_vars(&num_words,&i, &k, &ptr);
	num_words = ft_word_count(s ,c);
	ptr = ft_calloc(num_words + 1 , sizeof(*ptr));
	if (!ptr)
		return(NULL);
	while (i < num_words)
	{ 
		while(s[k] == c)
			k++;
		len= ft_wordlen(s + k, c);
		ptr[i] = ft_substr(s, k,len);
		if(!ptr[i])
			return (ft_free_split(ptr, i));
		k = len + k;
		i++;
	}
	ptr[i] = NULL;
	return (ptr);
}
// switch back to malloc and null
//pointer funciton 1
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int i = 0;
	char *out = NULL;
	if (!s || !f)
		return (NULL);
	out = malloc(ft_strlen(s) + 1);
	if (!out)
		return (NULL);
	while (s[i])
	{
		out[i] = f(i, s[i]);
		i++;
	}
	out[i] = '\0';
	return (out);
}


// pointer function 2
void ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int i;
	if (!s || !f)
		return;
	i = 0;
	while (s[i])
	{
		f(i, s + i);
		i++;
	}
}
# include <unistd.h>

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




// #include <stdio.h>

// int	main(void)
// {
// 	printf("test out: %i \n", ft_isupper(EOF));
// 	return (0);
// }
