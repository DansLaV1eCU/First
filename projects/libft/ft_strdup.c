/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llupache <llupache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:33:30 by llupache          #+#    #+#             */
/*   Updated: 2024/09/28 20:04:39 by llupache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	long	length;
	char	*ptr;
	char	*src1;
	int		count;

	length = ft_strlen(src);
	src1 = (char *)src;
	ptr = (char *)malloc((length + 1) * sizeof(int));
	if (!ptr)
		return (NULL);
	count = -1;
	while (src1[++count])
		ptr[count] = src1[count];
	ptr[count] = '\0';
	return (ptr);
}

// int	main(void)
// {
// 	char	*str;
// 	char	*dest;

// 	str = "tessdfsdaft";
// 	dest = ft_strdup(str);
// 	while (*dest)
// 		printf("%c", *dest++);
// 	//printf("%s\n", dest);
// 	return (0);
// }
