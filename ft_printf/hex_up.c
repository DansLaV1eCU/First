/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_up.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llupache <llupache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 19:12:28 by llupache          #+#    #+#             */
/*   Updated: 2024/10/02 19:58:12 by llupache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	cycle_hex_up(unsigned int nb, int count)
{
	static char	*abc = "0123456789ABCDEF";

	if (nb != 0)
	{
		count = cycle_hex_up(nb / 16, count + 1);
		write(1, &abc[nb % 16], 1);
	}
	return (count);
}

int	ft_put_hex_up(unsigned int nb, int count)
{
	if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
		count++;
	}
	else if (nb == 0)
	{
		write(1, "0", 1);
		count++;
		return (count);
	}
	count = cycle_hex_up(nb, count);
	return (count);
}
