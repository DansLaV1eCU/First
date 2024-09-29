/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llupache <llupache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 20:29:28 by llupache          #+#    #+#             */
/*   Updated: 2024/09/28 20:11:02 by llupache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	isinset(char ch, const char *set)
{
	char	*new;

	new = (char *)set;
	while (*new)
	{
		if (ch == *new)
			return (1);
		new ++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		len;
	char	*news1;

	news1 = (char *)s1;
	start = 0;
	while (news1[start] && isinset(news1[start], set))
		start++;
	len = 0;
	while (news1[start + len] && !isinset(news1[start + len], set))
		len++;
	return (ft_substr(s1, (unsigned int)start, (size_t)len));
}

// int main(void)
// {
// 	printf("%s", ft_strtrim("abchelloabd", "abcd"));
// }
