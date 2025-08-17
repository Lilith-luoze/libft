/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luozguo <luozguo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 22:23:03 by luozguo           #+#    #+#             */
/*   Updated: 2025/08/17 18:33:45 by luozguo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// continuously allocate memory and set them to bytes of zero
// how to detect overflow : use an unequality as condition constraint
void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	buffer;

	ptr = NULL;
	buffer = 0;
	if ((size && count > SIZE_MAX / size) || count == 0 || size == 0)
		return (NULL);
	buffer = count * size;
	ptr = malloc(buffer);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, buffer);
	return (ptr);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	i;

	i = 0;
	dup = malloc((ft_strlen(s) + 1) * sizeof(*s));
	if (dup == NULL)
		return (NULL);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
