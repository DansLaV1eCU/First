/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llupache <llupache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:06:09 by llupache          #+#    #+#             */
/*   Updated: 2024/09/29 15:41:18 by llupache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest_str, const void *src_str, size_t n)
{
	unsigned char	*new_str;
	unsigned char	*new_str2;

	if (!dest_str && !src_str && n > 0)
		return (NULL);
	new_str = (unsigned char *)dest_str;
	new_str2 = (unsigned char *)src_str;
	while (n--)
	{
		*new_str = *new_str2;
		new_str++;
		new_str2++;
	}
	return (dest_str);
}

// int	main(void)
// {
// 	void	*new_str;
// 	char	new[5] = "sdft";
// 	char	new2[5];

// 	new_str = ft_memcpy(new2, new, 4);
// 	printf("%s", (char *)new_str);
// }
