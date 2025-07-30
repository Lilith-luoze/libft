/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luozguo <luozguo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:50:13 by luozguo           #+#    #+#             */
/*   Updated: 2025/05/20 20:54:18 by luozguo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;

	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] = str[0] - ('z' - 'Z');
	i = 1;
	while (str[i])
	{
		if (!(str[i - 1] >= 'A' && str[i - 1] <= 'Z') && !(str[i - 1] >= 'a'
				&& str[i - 1] <= 'z') && !(str[i - 1] >= '0' && str[i
					- 1] <= '9'))
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] = str[i] - ('z' - 'Z');
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + ('z' - 'Z');
		i++;
	}
	return (str);
}
/*insane: there are only three common cases: the blank,
the word head, the word inner. there are two layers of conditions to check
when iterating over the whole str */

// #include <ctype.h>
// #include <stdio.h>
// #include <string.h>
// #include <unistd.h>

// int main()
// {

//     char str[] = "hi, How ARE you? cApItaL case";
// 	printf("%s", str);
//     printf("%s", ft_strcapitalize(str));

//     return (0);

// }
