/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlopez-m <rlopez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 12:17:54 by rlopez-m          #+#    #+#             */
/*   Updated: 2022/01/23 22:06:52 by rlopez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

// # define BUFFER_SIZE 4096

size_t	ft_strlcpy(char *dst, char *src, int dstsize);
char	*read_stdinput(int fd, char *mem_line);
char	*read_file(int fd, char *mem_line);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlcat(char *dst, char *src, size_t len);
size_t	ft_strlen(char *str);
char	*ft_strchr(char *str, int c);

#endif