/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luozguo <luozguo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:57:45 by luozguo           #+#    #+#             */
/*   Updated: 2025/05/20 20:52:53 by luozguo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//  Check printable or not using standard c function :
// isprint \0 is ascii 0. how to check this? -- ok. it
// is probably the only exception for the question.
int	ft_str_is_printable(char *str)
{
	while (*str)
	{
		if (*str >= 32 && *str <= 126)
			str++;
		else
			return (0);
	}
	return (1);
}

// #include <ctype.h>
// #include <stdio.h>
// #include <string.h>

// int main()
// {
//     char *str = "EWV\0";

//     printf("%i", ft_str_is_printable(str));
//     // printf("%i", isprint(127));
//     return (0);

// }
