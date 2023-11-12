/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcai <bcai@student.42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 11:21:04 by bcai              #+#    #+#             */
/*   Updated: 2023/11/12 01:52:32 by bcai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

char	*read_store_check(char *buffer, int fd, char *storage)
{
	char	*temp;
	ssize_t	bytes_read;

	if (!storage)
		storage = ft_strdup("");
	bytes_read = 1;
	while(bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		//printf("%zd bytes read\n", bytes_read);
		if (bytes_read < 0)
		{
			free (storage);
			return (NULL);
		}
		if (bytes_read == 0)
			return (storage);
		buffer[bytes_read] = '\0';
		//printf("inside buffer: %s\n", buffer);
		storage = ft_strjoin(storage, buffer);
		if (ft_strchr(storage, '\n'))
			break ;
	}
	return (storage);
}

char	*clear_line(char **storage)
{
	char	*temp;
	char	*line;

	temp = (*storage);
	while (*temp)
	{
		if (*temp == '\n')
			break ;
		temp++;
	}
	if (ft_strchr((*storage), '\n'))
	{
		if (!(*(temp + 1)))
			return (*storage);
		else
		{
			line = ft_substr((*storage), 0, temp - (*storage) + 1);
			(*storage) = ft_substr((*storage), temp - (*storage) + 1, ft_strlen(temp + 1));
		}
	}
	else
		return (*storage);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char	*buffer;
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return NULL;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return NULL;
	storage = read_store_check(buffer, fd, storage);
	//printf("now the storage content is %s\n", storage);
	line = clear_line(&storage);
	//printf("What's remained in storage is %s\n", storage);
	free(buffer);
	return (line);
}

int	main(void)
{
	int	fd;
	char	*line;
	char	*line2;
	char	*line3;

	fd = open("file.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s\n", line);
	line2 = get_next_line(fd);
	printf("%s\n", line2);
	line3 = get_next_line(fd);
	printf("%s\n", line3);
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	/*
	while (!line)
	{
		line = get_next_line(fd);
		printf("%s\n", line);
	}*/
	return (0);
}
		
