/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcai <bcai@student.42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 11:21:04 by bcai              #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/12/05 15:13:39 by bcai             ###   ########.fr       */
=======
/*   Updated: 2023/11/28 15:09:05 by bcai             ###   ########.fr       */
>>>>>>> 09f1aff8b25cbb805215f1f1734b065c9bbcba69
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*join_free(char *substorage, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(substorage, buffer);
	free(substorage);
	substorage = NULL;
	return (temp);
}

char	*read_store_check(char *buffer, int fd, char *substorage)
{
	ssize_t	bytes_read;

	if (!substorage)
		substorage = ft_strdup("");
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(substorage);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		if (bytes_read == 0)
		{
			substorage = join_free(substorage, buffer);
			break ;
		}
		substorage = join_free(substorage, buffer);
		if (ft_strchr(substorage, '\n'))
			break ;
	}
	return (substorage);
}

char	*free_cut(char *substorage, int index, int len)
{
	char	*temp;

	temp = ft_substr(substorage, index, len);
	free(substorage);
	(substorage) = NULL;
	return (temp);
}

char	*clear_line(char **substorage)
{
	char	*temp;
	char	*line;

	if (*(*substorage) == '\0')
	{
		free(*substorage);
		*substorage = NULL;
		return (NULL);
	}
	temp = (*substorage);
	while (*temp)
	{
		if (*temp == '\n')
		{
			line = ft_substr((*substorage), 0, temp - (*substorage) + 1);
			(*substorage) = free_cut(*substorage, temp - (*substorage) + 1,
					ft_strlen(temp + 1));
			return (line);
		}
		temp++;
	}
	line = ft_substr((*substorage), 0, ft_strlen(*substorage));
	free(*substorage);
	*substorage = NULL;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*storage[OPEN_MAX];
	char		*buffer;
	char		*line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	else if (read(fd, 0, 0) < 0)
	{
		free(storage[fd]);
		storage[fd] = NULL;
		return (NULL);
	}
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	storage[fd] = read_store_check(buffer, fd, storage[fd]);
	line = clear_line(&(storage[fd]));
	free(buffer);
	buffer = NULL;
	return (line);
}
