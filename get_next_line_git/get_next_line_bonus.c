/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llupache <llupache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 21:11:19 by llupache          #+#    #+#             */
/*   Updated: 2024/10/08 19:10:46 by llupache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*create_line1(char *res)
{
	char	*line;
	size_t	count;

	if (!res[0])
		return (NULL);
	count = 0;
	while (res[count] && res[count] != '\n')
		count++;
	line = (char *)malloc((count + 2) * sizeof(char *));
	if (!line)
	{
		free(res);
		res = NULL;
		return (NULL);
	}
	count = 0;
	while (res[count] && res[count] != '\n')
	{
		line[count] = res[count];
		count++;
	}
	if (res[count] && res[count] == '\n')
		line[count++] = '\n';
	line[count] = '\0';
	return (line);
}

char	*put_line1(char *temp, char *res)
{
	char	*new;
	int		count;
	int		i;
	char	*to_clean;

	new = (char *)malloc((str_len1(temp) + str_len1(res) + 1) * sizeof(char));
	if (!new)
		return (free_everything1(temp, res));
	to_clean = res;
	count = 0;
	i = 0;
	if (res)
		while (*res)
			new[count++] = *res++;
	while (temp[i])
		new[count++] = temp[i++];
	new[count] = '\0';
	free(to_clean);
	to_clean = NULL;
	return (new);
}

char	*main_cycle1(int fd, char *res)
{
	ssize_t	char_read;
	char	*temp;

	temp = (char *)malloc(BUFFER_SIZE + 1);
	if (!(temp))
	{
		free(res);
		res = NULL;
		return (NULL);
	}
	char_read = 1;
	while (char_read > 0)
	{
		char_read = read(fd, temp, BUFFER_SIZE);
		if (char_read == -1)
			return (free_everything1(temp, res));
		temp[char_read] = '\0';
		res = (put_line1(temp, res));
		if (!res)
			return (free_everything1(temp, res));
		if (ft_strchr1(res, '\n'))
			break ;
	}
	free(temp);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buffer[FOPEN_MAX];
	char		*res;

	if (BUFFER_SIZE <= 0 || fd >= FOPEN_MAX)
		return (NULL);
	buffer[fd] = main_cycle1(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	res = create_line1(buffer[fd]);
	buffer[fd] = new_temp1(buffer[fd]);
	return (res);
}

// int	main(void)
// {
// 	char	*res;
// 	int		fd;

// 	fd = open("test.txt", O_RDONLY);
// 	res = get_next_line1(fd);
// 	printf("%s", res);
// 	free(res);
// 	res = get_next_line1(fd);
// 	printf("%s", res);
// 	free(res);
// 	res = get_next_line1(fd);
// 	printf("%s", res);
// 	free(res);
// 	res = get_next_line1(fd);
// 	printf("%s", res);
// 	free(res);
// 	res = get_next_line1(fd);
// 	printf("%s", res);
// 	free(res);
// 	close(fd);
// 	return (0);
// }
