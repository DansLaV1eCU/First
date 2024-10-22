/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llupache <llupache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 16:40:04 by llupache          #+#    #+#             */
/*   Updated: 2024/10/02 19:57:54 by llupache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	opperate(va_list args, const char c, int count)
{
	if (c == 'c')
	{
		print_chr(va_arg(args, int));
		count++;
	}
	else if (c == 's')
		count = print_str(va_arg(args, char *), count);
	else if (c == 'p')
		count = print_void(va_arg(args, unsigned long long), count);
	else if (c == 'd' || c == 'i')
		count = ft_putnbr(va_arg(args, int), count);
	else if (c == 'u')
		count = ft_put_uns_nbr(va_arg(args, unsigned int), count);
	else if (c == 'x')
		count = ft_put_hex_low(va_arg(args, unsigned int), count);
	else if (c == 'X')
		count = ft_put_hex_up(va_arg(args, unsigned int), count);
	else if (c == '%')
		count += write(1, "%", 1);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str != '%')
		{
			write(1, str, 1);
			count++;
		}
		else
			count = opperate(args, *++str, count);
		str++;
	}
	va_end(args);
	return (count);
}

// int	main(void)
// {
// 	int	nb;
// //	int	r1;
// 	int	r2;

// 	nb = 23453;
// 	//r1 = printf(" NULL %s NULL \n", NULL);
// 	r2 = ft_printf(" NULL %s NULL \n", NULL);
// 	printf("%d", r2);
// 	return (0);
// }
