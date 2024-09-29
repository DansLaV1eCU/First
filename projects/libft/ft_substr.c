/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llupache <llupache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 19:18:08 by llupache          #+#    #+#             */
/*   Updated: 2024/09/27 20:46:01 by llupache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		count;
	char	*str;
	char	*substr;

	str = (char *)s;
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	count = 0;
	while (count < (int)len)
	{
		substr[count] = str[start];
		start++;
		count++;
	}
	substr[count] = '\0';
	return (substr);
}

// int	main(void)
// {
// 	char	*str;
// 	char	*new;

// 	str = "here we come again";
// 	new = ft_substr(str, 3, 3);
// 	printf("%s", new);
// }
