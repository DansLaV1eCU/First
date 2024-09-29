/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnr copy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llupache <llupache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 13:43:03 by llupache          #+#    #+#             */
/*   Updated: 2024/09/28 16:13:15 by llupache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	cycle_size(int n, int size)
{
	if (n != 0)
		size += cycle_size(n / 10, size) + 1;
	return (size);
}

char	*to_str(int n, int size, char *s)
{
	int	count;

	count = 0;
	while (n != 0)
	{
		s[size - count - 1] = n % 10 + '0';
		n /= 10;
		count++;
	}
	return (s);
}

char	*create_str(int n)
{
	int		size;
	char	*new;

	if (n < 0)
	{
		size = cycle_size(-n, 0) + 2;
		new = (char *)malloc(size * sizeof(char));
		if (!new)
			return (NULL);
		new[0] = '-';
		new = to_str(-n, size - 1, new);
		new[size - 1] = '\0';
		return (new);
	}
	else
	{
		size = cycle_size(n, 0) + 1;
		new = (char *)malloc(size * sizeof(char));
		if (!new)
			return (NULL);
		new = to_str(n, size - 1, new);
		new[size - 1] = '\0';
		return (new);
	}
}

char	*ft_itoa(int n)
{
	if (n == -2147483648)
		return ("-2147483648");
	else if (n == 0)
		return ("0");
	else
		return (create_str(n));
}

// int	main(void)
// {
// 	int	number;

// 	number = -123;
// 	printf("%s", ft_itoa(number));
// 	return (0);
// }
