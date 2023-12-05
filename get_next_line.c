/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcai <bcai@student.42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 11:21:04 by bcai              #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/12/05 15:12:30 by bcai             ###   ########.fr       */
=======
/*   Updated: 2023/11/28 15:08:45 by bcai             ###   ########.fr       */
>>>>>>> 09f1aff8b25cbb805215f1f1734b065c9bbcba69
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*join_free(char *storage, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(storage, buffer);
	free(storage);
	storage = NULL;
	return (temp);
}

char	*read_store_check(char *buffer, int fd, char *storage)
{
	ssize_t	bytes_read;

	if (!storage)
		storage = ft_strdup("");
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(storage);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		if (bytes_read == 0)
		{
			storage = join_free(storage, buffer);
			break ;
		}
		storage = join_free(storage, buffer);
		if (ft_strchr(storage, '\n'))
			break ;
	}
	return (storage);
}

char	*free_cut(char *storage, int index, int len)
{
	char	*temp;

	temp = ft_substr(storage, index, len);
	free(storage);
	(storage) = NULL;
	return (temp);
}

char	*clear_line(char **storage)
{
	char	*temp;
	char	*line;

	if (*(*storage) == '\0')
	{
		free(*storage);
		*storage = NULL;
		return (NULL);
	}
	temp = (*storage);
	while (*temp)
	{
		if (*temp == '\n')
		{
			line = ft_substr((*storage), 0, temp - (*storage) + 1);
			(*storage) = free_cut(*storage, temp - (*storage) + 1,
					ft_strlen(temp + 1));
			return (line);
		}
		temp++;
	}
	line = ft_substr((*storage), 0, ft_strlen(*storage));
	free(*storage);
	*storage = NULL;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(storage);
		storage = NULL;
		return (NULL);
	}
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	storage = read_store_check(buffer, fd, storage);
	line = clear_line(&storage);
	free(buffer);
	buffer = NULL;
	return (line);
}
/*
int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s\n", line);
		line = get_next_line(fd);
	}
	return (0);
}*/
