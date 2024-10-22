/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llupache <llupache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:44:30 by llupache          #+#    #+#             */
/*   Updated: 2024/10/02 18:10:44 by llupache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
void	print_chr(const char c);
int		print_str(char *str, int count);
int		print_void(unsigned long long ptr, int count);
int		ft_putnbr(int nb, int count);
int		ft_put_uns_nbr(unsigned int nb, int count);
int		ft_put_hex_up(unsigned int nb, int count);
int		ft_put_hex_low(unsigned int nb, int count);

#endif
