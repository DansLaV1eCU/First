/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llupache <llupache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 19:00:16 by llupache          #+#    #+#             */
/*   Updated: 2024/09/28 20:09:41 by llupache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int search_str)
{
	char	*new;
	int		count;

	count = ft_strlen(str);
	new = (char *)str;
	while (count != 0)
	{
		count--;
		if (new[count] == search_str)
			return (&new[count]);
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	*str;
// 	char	c;
// 	char	*new;

// 	str = "hello";
// 	c = 'a';
// 	new = strrchr(str, c);
// 	if (new)
// 	{
// 		printf("%c", *new);
// 	}
// 	else
// 		printf("Not included");
// 	return (0);
// }
