/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luozguo <luozguo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:57:51 by luozguo           #+#    #+#             */
/*   Updated: 2025/05/20 20:53:03 by luozguo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	char	*ori_str;

	ori_str = str;
	while (*str)
	{
		if (*str >= 'A' && *str <= 'Z')
			*str = *str + ('z' - 'Z');
		str++;
	}
	return (ori_str);
}

// #include <ctype.h>
// #include <stdio.h>
// #include <string.h>

// int main()
// {
//     // test if it's only a read-only string, can YOU modify it? -No.
//     // char *str = "i am pow. you are POW\0";
//     // printf("%s", ft_strlowcase(str));

//     // the def successful version:
//     char str[] = "i am pow. you are POW\0";

//     printf("%s", ft_strlowcase(str));

//     return (0);

// }
