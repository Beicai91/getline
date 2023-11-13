/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcai <bcai@student.42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 08:51:42 by bcai              #+#    #+#             */
/*   Updated: 2023/11/13 08:51:44 by bcai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <limits.h>
# include <stddef.h>

char	*get_next_line(int fd);
char	*read_store_check(char *buffer, int fd, char *substorage);
char	*join_free(char *substorage, char *buffer);
char	*clear_line(char **substorage);
char	*free_cut(char *substorage, int index, int len);

#endif