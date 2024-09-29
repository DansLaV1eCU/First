/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llupache <llupache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:06:05 by llupache          #+#    #+#             */
/*   Updated: 2024/09/28 20:02:55 by llupache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		general_size;
	char	*new;
	char	*newcpy;
	char	*news1;
	char	*news2;

	general_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	new = (char *)malloc(general_size * sizeof(char));
	if (!new)
		return (NULL);
	news1 = (char *)s1;
	news2 = (char *)s2;
	newcpy = new;
	while (*news1)
		*new++ = *news1++;
	while (*news2)
		*new++ = *news2++;
	*new = '\0';
	return (newcpy);
}

// int	main(void)
// {
// 	char	*str1;
// 	char	*str2;
// 	char	*new;

// 	str1 = "88";
// 	str2 = "sdfgfd";
// 	new = ft_strjoin(str1, str2);
// 	printf("%s", new);
// }
