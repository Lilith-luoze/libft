/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_more.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luozguo <luozguo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 22:23:47 by luozguo           #+#    #+#             */
/*   Updated: 2025/08/16 22:23:48 by luozguo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
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


/*
	needle is null-terminated; haystack might not. the stop condition would be either
	condition is met : len characters are searched or met a '\0'
	so it's not that a function should never segfault, but it should never segfault
	when the user is using it correctly.
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

	while (haystack[i] && i + nlen <= len )
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