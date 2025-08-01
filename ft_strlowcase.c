/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luozguo <luozguo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:57:51 by luozguo           #+#    #+#             */
/*   Updated: 2025/08/01 17:58:42 by luozguo          ###   ########.fr       */
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

#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char str_2[] = "i am pow. you are POW";

    printf("test if this string is mutable:  %s", ft_strlowcase(str_2));

    return (0);

}
