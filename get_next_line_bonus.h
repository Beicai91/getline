/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcai <bcai@student.42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 08:51:42 by bcai              #+#    #+#             */
/*   Updated: 2023/11/22 13:56:38 by bcai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

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
char	*get_next_line(int fd);
char	*read_store_check(char *buffer, int fd, char *substorage);
char	*join_free(char *substorage, char *buffer);
char	*clear_line(char **substorage);
char	*free_cut(char *substorage, int index, int len);

#endif
