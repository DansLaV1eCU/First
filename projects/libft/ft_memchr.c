/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llupache <llupache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 19:00:16 by llupache          #+#    #+#             */
/*   Updated: 2024/09/28 19:46:46 by llupache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int search_str, size_t n)
{
	char	*new;
	int		count;

	count = 0;
	new = (char *)str;
	while (new[count] && count < (int)n)
	{
		if (new[count] == search_str)
			return (&new[count]);
		count++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	*str;
// 	char	c;
// 	char	*new;

// 	str = "hello";
// 	c = 'l';
// 	new = memchr((void *)str, c, 3);
// 	if (new)
// 	{
// 		printf("%c", *new);
// 	}
// 	else
// 		printf("Not included");
// 	return (0);
// }
