/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llupache <llupache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:06:09 by llupache          #+#    #+#             */
/*   Updated: 2024/09/28 20:18:54 by llupache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *str, size_t n)
{
	unsigned char	*new_str;

	new_str = (unsigned char *)str;
	while (n)
	{
		*new_str = '\0';
		new_str++;
		n--;
	}
	return (str);
}

// int	main(void)
// {
// 	void	*new_str;
// 	char new [5] = "sdft";

// 	new_str = ft_bzero(new, 4);
// 	printf("%s", (char *)new_str);
// }
