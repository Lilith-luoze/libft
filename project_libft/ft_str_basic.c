/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_basic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luozguo <luozguo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 22:23:45 by luozguo           #+#    #+#             */
/*   Updated: 2025/08/16 22:23:46 by luozguo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// copy the src string to dst. output the length of the trying-to-create,
#include "libft.h"


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