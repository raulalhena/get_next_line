/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_old.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlopez-m <rlopez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 19:24:14 by rlopez-m          #+#    #+#             */
/*   Updated: 2022/01/26 15:06:34 by rlopez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_stdinput(int fd, char *mem_line)
{
	int		nbytes;
	char	*buff;

	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	nbytes = 1;
	while (nbytes > 0 && !ft_strchr(mem_line, '\n'))
	{
		nbytes = read(fd, buff, BUFFER_SIZE);
		if (nbytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[nbytes] = '\0';
		mem_line = ft_strjoin(mem_line, buff);
	}
	if (mem_line[0] == '\0')
		mem_line = NULL;
	printf("STDINPUT F MEM_LINE: %s\n", mem_line);
	free(buff);
	return (mem_line);
}

char	*read_file(int fd, char *mem_line)
{
	int		nbytes;
	char	*buff;

	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	nbytes = 1;
	while (nbytes > 0 && !ft_strchr(mem_line, '\n'))
	{
		nbytes = read(fd, buff, BUFFER_SIZE);
		if (nbytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[nbytes] = '\0';
		mem_line = ft_strjoin(mem_line, buff);
	}
	free(buff);
	return (mem_line);
}

char	*ft_read_line(char *mem_line)
{
	int		i;
	char	*str;

	if (!mem_line)
		return (NULL);
	i = 0;
	while (mem_line[i] && mem_line[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (mem_line[i] && mem_line[i] != '\n')
	{
		str[i] = mem_line[i];
		i++;
	}
	if (mem_line[i] == '\n')
	{
		str[i] = mem_line[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_drop_memline(char *mem_line)
{
	int		i;
	char	*str;

	i = 0;
	// printf("DROP MEMLINE F: mem_line[i]: %c\n", mem_line[i]);
	while (mem_line[i] && mem_line[i] != '\n')
		i++;
	if (!mem_line[i])
	{
		free(mem_line);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * ft_strlen(mem_line) - i + 1);
	if (!str)
		return (NULL);
	i++;
	// printf("i: %d\n", i);
	// printf("DROP MEMLINE F: mem_line2: %s\n", &mem_line[ft_strlen(mem_line) - i]);
	ft_strlcpy(str, mem_line, ft_strlen(mem_line) - i);
	free(mem_line);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*mem_line;
	char		*str;

	str = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	// if (fd == 0)
	// {
		mem_line = read_stdinput(fd, mem_line);
		if (!mem_line)
			return (NULL);
		// printf("GET_NEXT_LINE F: mem_line: %s\n", mem_line);
		str = ft_read_line(mem_line);
		// printf("GET_NEXT_LINE F: str: %s\n", str);
		mem_line = ft_drop_memline(mem_line);
		// printf("GET_NEXT_LINE F: mem_line2: %s\n", mem_line);
	// }
	// else
	// {
	// 	mem_line = read_file(fd, mem_line);
	// 	if (!mem_line)
	// 		return (NULL);
	// 	str = ft_read_line(mem_line);
	// 	mem_line = ft_drop_memline(mem_line);
	// }
	return (str);
}

int	main(int argc, char *argv[])
{
	char	*str;

	str = NULL;
	if (argc == 1)
		printf("0 for stdin or text file path please.\n");
	else
	{
		if (argv[1][0] == '0')
		{
			str = get_next_line(0);
			printf("%s", str);
		}
		else
		{
			str = get_next_line(open(argv[1], O_RDONLY));
			printf("%s", str);
		}
	}
	return (0);
