/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llupache <llupache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 19:00:16 by llupache          #+#    #+#             */
/*   Updated: 2024/09/28 19:51:26 by llupache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strchr(const char *str, int search_str)
{
	char	*new;

	new = (char *)str;
	while (*new)
	{
		if (*new == search_str)
			return (new);
		new ++;
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
// 	new = strchr(str, c);
// 	if (new)
// 	{
// 		printf("%c", *new);
// 	}
// 	else
// 		printf("Not included");
// 	return (0);
// }
