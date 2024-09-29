/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llupache <llupache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:59:43 by llupache          #+#    #+#             */
/*   Updated: 2024/09/28 19:47:04 by llupache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned int	count;
	char			*s1;
	char			*s2;

	s1 = (char *)str1;
	s2 = (char *)str2;
	count = 0;
	while (count < n && (s1[count] && s2[count]))
	{
		if (s1[count] != s2[count])
			return (s1[count] - s2[count]);
		count++;
	}
	if (count < n)
	{
		return (s1[count] - s2[count]);
	}
	return (0);
}

// int	main(void)
// {
// 	char	*c1;
// 	char	*c2;

// 	c1 = "abc";
// 	c2 = "abd";
// 	printf("%d", ft_memcmp((void *)c1, (void *)c2, 3));
// }
