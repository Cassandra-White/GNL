/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrissan <akrissan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 23:35:13 by akrissan          #+#    #+#             */
/*   Updated: 2020/10/15 23:35:55 by akrissan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_malloc(size_t size)
{
	char	*s;
	size_t	i;

	i = 0;
	if (!(s = malloc(sizeof(size + 1))))
		return (NULL);
	while (i < size)
		s[i++] = 0;
	s[i] = '\0';
	return (s);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;
	size_t	size;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	size = ft_strlen(s1) + ft_strlen(s2);
	if (!(string = (char *)malloc((size + 1) * sizeof(char))))
		return (NULL);
	while (*s1)
		string[i++] = *(s1++);
	while (*s2)
		string[i++] = *(s2++);
	string[i] = '\0';
	return (string);
}

char	*ft_substr(char const *s, unsigned int str, size_t len)
{
	size_t		i;
	char		*copy;

	i = 0;
	if (!s || !(copy = malloc(((len + 1) * sizeof(char)))))
		return (0);
	if (str > ft_strlen(s))
	{
		copy[0] = '\0';
		return (copy);
	}
	while (i < len && s[str])
	{
		copy[i] = s[str];
		i++;
		str++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_strdup(const char *s1)
{
	char	*copy;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	if (!(copy = (char *)malloc((i * sizeof(char)) + 1)))
		return (0);
	i = -1;
	while (s1[++i])
		copy[i] = s1[i];
	copy[i] = '\0';
	return (copy);
}

char	*ft_strchr(const char *str, int c)
{
	if (c == 0)
	{
		while (*str)
			str++;
		return ((char*)str);
	}
	while (*str)
	{
		if (*str == (unsigned char)c)
			return ((char*)str);
		str++;
	}
	return (0);
}
