/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcai <bcai@student.42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:17:17 by bcai              #+#    #+#             */
/*   Updated: 2023/11/21 11:00:56 by bcai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <limits.h>
# include <stddef.h>

int		ft_strlen(char *s);
char	*ft_substr(char *origin, int start, int len);
char	*ft_strdup(char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*read_store_check(char *buffer, int fd, char *storage);
char	*clear_line(char **storage);
char	*get_next_line(int fd);
char	*join_free(char *storage, char *buffer);
char	*free_cut(char *storage, int index, int len);

#endif
