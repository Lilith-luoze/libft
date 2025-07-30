/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luozguo <luozguo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 18:19:57 by luozguo           #+#    #+#             */
/*   Updated: 2025/05/15 18:19:58 by luozguo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	len_dst;
	unsigned int	len_src;
	unsigned int	i;

	i = 0;
	len_dst = ft_strlen(dest);
	len_src = ft_strlen(src);
	if (size <= len_dst)
		return (size + len_src);
	while (i + len_dst + 1 < size && src[i])
	{
		dest[i + len_dst] = src[i];
		i++;
	}
	dest[i + len_dst] = '\0';
	return (len_dst + len_src);
}
/*1. strlcat() always returns the length of the string it tried to create: 
min(size ,len_dest) + len_src 
2.  C strings are measured by character count, not including the null terminator.
It only return the string size without null-terminator.
*/
// #include <stdio.h>
// #include <string.h>

//it is really a pain.
// int main()
// {
//     char dest_ft[100] = "To live or "; //len_dst == 11
//     char dest_builtin[100] = "To live or ";
//     char *src = "death, that's a question"; //len_src == 24
//     unsigned int size = 5; //35 ,32
//     printf("%u %s\n", ft_strlcat(dest_ft, src , size), dest_ft);
//     printf("%lu %s\n", strlcat(dest_builtin , src, size), dest_builtin );

//     return (0);
// }