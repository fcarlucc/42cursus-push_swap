/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarlucc <fcarlucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 02:01:35 by fcarlucc          #+#    #+#             */
/*   Updated: 2023/06/21 18:18:23 by fcarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

static int	line_len(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	return (i);
}

static int	ft_cleanbuff(char *buff)
{
	int	i;
	int	j;
	int	newline;

	i = 0;
	j = 0;
	newline = 0;
	while (buff[i])
	{
		if (newline)
			buff[j++] = buff[i];
		if (buff[i] == '\n')
			newline = 1;
		buff[i++] = '\0';
	}
	return (newline);
}

static char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	char	*s3;

	i = 0;
	s3 = malloc(line_len(s1) + line_len(s2) + 1);
	if (!s3)
		return (NULL);
	while (s1 && s1[i])
	{	
		s3[i] = s1[i];
		i++;
	}
	free(s1);
	while (*s2)
	{
		s3[i++] = *s2;
		if (*s2++ == '\n')
			break ;
	}
	s3[i] = '\0';
	return (s3);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*readline;
	int			i;

	i = 0;
	if (BUFFER_SIZE < 1 || read(fd, buff, 0) < 0)
	{
		while (buff[i])
			buff[i++] = 0;
		return (NULL);
	}
	readline = NULL;
	while (*buff || read(fd, buff, BUFFER_SIZE) > 0)
	{
		readline = ft_strjoin(readline, buff);
		if (ft_cleanbuff(buff))
			break ;
	}
	return (readline);
}
