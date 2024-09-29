/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llupache <llupache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:42:26 by llupache          #+#    #+#             */
/*   Updated: 2024/09/28 20:01:28 by llupache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	length(char *str)
{
	int	count;

	count = 0;
	while (str[count])
	{
		count++;
	}
	return (count);
}

long unsigned int	count_words(char *str, char c)
{
	int	count;
	int	flag;
	int	words_count;

	count = 0;
	words_count = 0;
	flag = 1;
	while (str[count])
	{
		if (str[count] != c && flag == 1)
			words_count++;
		flag = 0;
		if (str[count] == c)
			flag = 1;
		count++;
	}
	return (words_count);
}

char	*create_word(char *str, char c, char **lst, int lst_index)
{
	long unsigned int	len;
	int					count;
	char				*word;
	char				*temp;

	temp = str;
	len = 0;
	count = 0;
	while (*str && *str++ != c)
		len++;
	word = (char *)malloc(len * sizeof(char) + 1);
	str = temp;
	while (*str && *str != c)
		word[count++] = *str++;
	while (*str && *str == c)
		str++;
	word[count] = '\0';
	lst[lst_index] = word;
	return (str);
}

char	**ft_split(char *str, char c)
{
	char	**list;
	int		list_count;

	list = (char **)malloc(count_words(str, c) * sizeof(char *) + 1);
	if (!list)
		return (NULL);
	list_count = 0;
	while (*str)
	{
		if (*str != c)
			str = create_word(str, c, list, list_count++);
		else
			str++;
	}
	list[list_count] = NULL;
	return (list);
}

// int	main(void)
// {
// 	char	*str;
// 	char	**new;

// 	str = "aaaahealloaaabeallaa";
// 	new = ft_split(str, 'a');
// 	while (*new != NULL)
// 	{
// 		printf("%s, ", *new);
// 		new ++;
// 	}
// }
