/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luozguo <luozguo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:56:34 by luozguo           #+#    #+#             */
/*   Updated: 2025/05/21 12:56:35 by luozguo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int ft_strlen(char *str)
{
    int i;
    i = 0;
    while(*str)
    {
        str++;
        i++;
    }
    return (i);
}

// # include <stdio.h>
// # include <string.h>

// int main()
// {
//     char *str = "12345";
//     printf("%i", ft_strlen(str));
//     return (0);
// }