/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 18:25:44 by jamendoe          #+#    #+#             */
/*   Updated: 2022/12/09 18:26:18 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0' && *s != (char) c)
		s++;
	if (*s == (char) c)
		return ((char *) s);
	else
		return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*sj;

	if (!s1 || !s2)
		return (NULL);
	sj = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!sj)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		sj[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		sj[i + j] = s2[j];
		j++;
	}
	sj[i + j] = '\0';
	return (sj);
}

int	ft_line_len(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
	{
		if (buffer[i] == '\0')
			break ;
		i++;
	}
	return (i);
}

int	ft_line_break(char *buffer)
{
	int	line_break;

	if (!ft_strchr(buffer, '\n'))
		line_break = 0;
	else
		line_break = 1;
	return (line_break);
}
