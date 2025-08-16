/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luozguo <luozguo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 22:23:37 by luozguo           #+#    #+#             */
/*   Updated: 2025/08/16 22:23:38 by luozguo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	if (!dst && !src)
		return (NULL);
	i = 0;
	ptr_dst = (unsigned char *)dst;
	while (i < n)
	{
		ptr_dst[i] = ptr_src[i];
		i++;
	}
	return (dst);
}
