/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llupache <llupache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 18:33:39 by llupache          #+#    #+#             */
/*   Updated: 2024/10/02 19:58:22 by llupache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ptr_to_hex(unsigned long long ptr, int count)
{
	const char	*abc = "0123456789abcdef";

	if (ptr != 0)
	{
		count = ptr_to_hex(ptr / 16, count + 1);
		write(1, &abc[ptr % 16], 1);
	}
	return (count);
}

int	print_void(unsigned long long ptr, int count)
{
	if (ptr == 0)
	{
		write(1, "(nil)", 5);
		count += 5;
		return (count);
	}
	else
	{
		write(1, "0x", 2);
		count = ptr_to_hex(ptr, count);
		return (count + 2);
	}
}
