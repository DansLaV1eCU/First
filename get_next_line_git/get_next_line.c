/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llupache <llupache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 21:11:19 by llupache          #+#    #+#             */
/*   Updated: 2024/10/08 19:07:53 by llupache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*create_line(char *res)
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

char	*put_line(char *temp, char *res)
{
	char	*new;
	int		count;
	int		i;
	char	*to_clean;

	new = (char *)malloc((str_len(temp) + str_len(res) + 1) * sizeof(char));
	if (!new)
		return (free_everything(temp, res));
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

char	*main_cycle(int fd, char *res)
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
			return (free_everything(temp, res));
		temp[char_read] = '\0';
		res = (put_line(temp, res));
		if (!res)
			return (free_everything(temp, res));
		if (ft_strchr(res, '\n'))
			break ;
	}
	free(temp);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*res;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	buffer = main_cycle(fd, buffer);
	if (!buffer)
		return (NULL);
	res = create_line(buffer);
	buffer = new_temp(buffer);
	return (res);
}

// int	main(void)
// {
// 	char	*res;
// 	int		fd;

// 	fd = open("test.txt", O_RDONLY);
// 	res = get_next_line(fd);
// 	printf("%s", res);
// 	free(res);
// 	res = get_next_line(fd);
// 	printf("%s", res);
// 	free(res);
// 	res = get_next_line(fd);
// 	printf("%s", res);
// 	free(res);
// 	res = get_next_line(fd);
// 	printf("%s", res);
// 	free(res);
// 	res = get_next_line(fd);
// 	printf("%s", res);
// 	free(res);
// 	close(fd);
// 	return (0);
// }
