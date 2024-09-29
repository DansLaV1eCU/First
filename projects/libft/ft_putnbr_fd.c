/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llupache <llupache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 13:43:03 by llupache          #+#    #+#             */
/*   Updated: 2024/09/28 19:49:02 by llupache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	cycle(int nb, int fd)
{
	char	number;

	if (nb != 0)
	{
		cycle(nb / 10, fd);
		number = (nb % 10) + '0';
		write(fd, &number, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		n = -n;
		write(fd, "-", 1);
	}
	else if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	cycle(n, fd);
}

/* int	main(void)
{
	int	number;

	number = -123;
	ft_putnbr(number);
	return (0);
} */