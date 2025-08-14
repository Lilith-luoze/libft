#include "libft.h"



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
