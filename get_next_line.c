/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlopez-m <rlopez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:02:39 by rlopez-m          #+#    #+#             */
/*   Updated: 2022/01/27 15:57:51 by rlopez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char *mem_line)
{
	int		nbytes;
	char	*buff;

	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	nbytes = 1;
	while (nbytes > 0)
	{
		nbytes = read(fd, buff, BUFFER_SIZE);
		if (nbytes < 1)
		{
			free (buff);
			return (NULL);
		}
		buff[nbytes] = '\0';
		mem_line = ft_strjoin(mem_line, buff);
		if (ft_strchr(mem_line, '\n'))
			break ;
	}
	return (mem_line);
}

char	*get_line(char *mem_line)
{
	char	*line;
	int		i;
	int		line_len;

	if (!mem_line)
		return (NULL);
	line_len = ft_strlen(mem_line);
	i = 0;
	while (!mem_line[i] && mem_line[i] != '\n')
		i++;
	if (!mem_line)
		return (NULL);
	line = (char *) malloc(sizeof(char) * line_len + 2);
	if (!line)
		return (NULL);
	line[line_len + 1] = '\n';
	line[line_len + 2] = '\0';
	ft_strlcpy(line, mem_line, line_len);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*mem_line;
	char		*line;

	line = NULL;
	if (!fd || !BUFFER_SIZE)
		return (NULL);
	mem_line = read_line(fd, mem_line);
	line = get_line(mem_line);
	return (line);
}

// int	main(void)
// {
// 	int	fd;

// 	fd = open("test.txt", O_RDONLY);
// 	printf("%s", get_next_line(fd));
// 	close(fd);
// 	return (0);
// }
