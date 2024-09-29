/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llupache <llupache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 17:58:58 by llupache          #+#    #+#             */
/*   Updated: 2024/09/28 20:13:19 by llupache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*calloc(size_t nitems, size_t size)
{
	void	*new;
	size_t	total_len;

	total_len = nitems * size;
	if (total_len == 0 || total_len / nitems != size)
		return (NULL);
	new = malloc(total_len);
	if (new == NULL)
	{
		return (NULL);
	}
	new = ft_memset(new, 0, total_len);
	return (new);
}
