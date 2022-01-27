/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlopez-m <rlopez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 19:18:10 by rlopez-m          #+#    #+#             */
/*   Updated: 2022/01/24 18:13:03 by rlopez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcpy(char *dst, char *src, int dstsize)
{
	size_t	srcsize;
	char	*cpy_dst;
	char	*cpy_src;

	cpy_dst = dst;
	cpy_src = (char *)src;
	srcsize = ft_strlen(cpy_src);
	if (!src)
		return (srcsize);
	if (dstsize)
	{
		while (dstsize-- > 1 && *cpy_src != '\0')
			*(cpy_dst++) = *(cpy_src++);
		*cpy_dst = '\0';
	}
	return (srcsize);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	new_len;
	char	*ptrs;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_len = s1_len + s2_len;
	ptrs = (char *)malloc(sizeof(char) * new_len + 1);
	if (!ptrs)
		return (NULL);
	ft_strlcpy(ptrs, s1, s1_len + 1);
	ft_strlcat(ptrs, s2, new_len + 1);
	return (ptrs);
}

size_t	ft_strlcat(char *dst, char *src, size_t len)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	src_index;

	if (!src)
		return (0);
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (len <= dst_len)
		return (len + src_len);
	src_index = 0;
	while (src[src_index] != '\0' && len > (dst_len + 1))
		dst[dst_len++] = src[src_index++];
	dst[dst_len] = '\0';
	src_len = 0;
	return (dst_len + ft_strlen(&src[src_index]));
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i++])
		;
	return (i - 1);
}

char	*ft_strchr(char *str, int c)
{
	int		i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	if (str[i] == c)
		return (&str[i]);
	return (NULL);
}
