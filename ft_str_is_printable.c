/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luozguo <luozguo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:57:45 by luozguo           #+#    #+#             */
/*   Updated: 2025/08/01 18:01:46 by luozguo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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

// #include <stdio.h>
// #include <string.h>

// int main()
// {
//     char *str = "EWV";

//     printf("%i", ft_str_is_printable(str));
//     // printf("%i", isprint(127));
//     return (0);

// }
