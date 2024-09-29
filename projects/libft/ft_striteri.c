/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llupache <llupache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 17:35:19 by llupache          #+#    #+#             */
/*   Updated: 2024/09/28 20:04:03 by llupache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	some(unsigned int n, char *c)
// {
// 	c[n] = '1';
// }

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	count;

	count = 0;
	while (s[count])
		f(count++, s);
}

// int	main(void)
// {
// 	char	*new;

// 	new = (char *)malloc(4 * sizeof(char));
// 	new[0] = '1';
// 	new[1] = '2';
// 	new[2] = '3';
// 	new[3] = '\0';
// 	ft_striteri(new, some);
// 	printf("%s", new);
// }
