/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llupache <llupache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 17:19:22 by llupache          #+#    #+#             */
/*   Updated: 2024/10/08 19:09:41 by llupache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

ssize_t	str_len1(char *str)
{
	ssize_t	count;

	if (!str)
		return (0);
	count = 0;
	while (str[count])
		count++;
	return (count);
}

char	*free_everything1(char *temp, char *res)
{
	free(res);
	free(temp);
	temp = NULL;
	return (NULL);
}

char	*free_buf1(char *buf)
{
	free(buf);
	buf = NULL;
	return (NULL);
}

char	*new_temp1(char *buf)
{
	char	*new;
	size_t	count;
	size_t	i;

	if (!buf)
		return (NULL);
	count = 0;
	while (buf[count] && buf[count] != '\n')
		count++;
	if (!buf[count])
		return (free_buf1(buf));
	new = (char *)malloc(str_len1(buf) - count);
	if (!new)
		return (free_buf1(buf));
	i = 0;
	count++;
	while (buf[count])
		new[i++] = buf[count++];
	new[i] = '\0';
	free(buf);
	buf = NULL;
	return (new);
}

char	*ft_strchr1(const char *s, int c)
{
	unsigned char	*chr;

	chr = (unsigned char *)s;
	while (*chr != (unsigned char)c)
	{
		if (!*chr)
			return (NULL);
		chr++;
	}
	return ((char *)chr);
}
