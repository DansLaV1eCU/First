/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llupache <llupache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:59:43 by llupache          #+#    #+#             */
/*   Updated: 2024/09/28 20:16:52 by llupache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	int		count1;
	int		count2;
	char	*str1;
	char	*to_find1;

	str1 = (char *)str;
	to_find1 = (char *)to_find;
	if (to_find1[0] == '\0')
		return (str1);
	count1 = 0;
	while (str1[count1] && count1 < (int)n)
	{
		count2 = 0;
		while (str1[count1 + count2] == to_find1[count2] && count1
			+ count2 < (int)n)
			count2++;
		if (!to_find1[count2])
			return (&str1[count1]);
		count1++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	const char	*big;
// 	const char	*small;
// 	char		*new;
// 	size_t		n;

// 	big = "hehehllo";
// 	small = "hehl";
// 	n = 6;
// 	new = ft_strnstr(big, small, n);
// 	if (*new)
// 	{
// 		while (*new)
// 		{
// 			printf("%c", *new);
// 			new ++;
// 		}
// 	}
// 	else
// 		printf("No");
// }
