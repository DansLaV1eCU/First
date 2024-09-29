/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llupache <llupache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:59:43 by llupache          #+#    #+#             */
/*   Updated: 2024/09/28 20:09:16 by llupache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	count;

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
// 	printf("%d", ft_strncmp(c1, c2, 2));
// }
