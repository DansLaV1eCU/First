/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llupache <llupache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 17:35:19 by llupache          #+#    #+#             */
/*   Updated: 2024/09/28 20:18:43 by llupache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	some(unsigned int n, char c)
// {
// 	return (c + n);
// }

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	int		count;

	new = (char *)malloc(ft_strlen(s) + 1);
	if (new == NULL)
		return (NULL);
	count = 0;
	while (s[count])
	{
		new[count] = f(count, s[count]);
		count++;
	}
	return (new);
}

// int	main(void)
// {
// 	char	*new;

// 	new = ft_strmapi("123", some);
// 	printf("%s", new);
// }
