#include "libft.h"

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