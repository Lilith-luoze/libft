/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luozguo <luozguo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:57:33 by luozguo           #+#    #+#             */
/*   Updated: 2025/05/20 20:51:42 by luozguo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	while (*str)
	{
		if ((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z'))
			str++;
		else
			return (0);
	}
	return (1);
}

// #include <stdio.h>
// #include <string.h>
// #include <unistd.h>

// int main()
// {
//     char *str = "trythisone\0";

//     printf("%i", ft_str_is_alpha(str));

//     return (0);

// }
