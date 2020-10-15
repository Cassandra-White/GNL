/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrissan <akrissan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 23:32:57 by akrissan          #+#    #+#             */
/*   Updated: 2020/10/15 23:33:27 by akrissan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <limits.h>

int		get_next_line(int fd, char **line);

int		ft_end(char **line, char **save, int fd, int bytes);
int		ft_line(char **line, char **save, int fd, int i);
int		ft_next_step(char **line, char **save, int fd, int bytes);
size_t	ft_strlen(const char *s1);
char	*ft_malloc(size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int str, size_t len);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *str, int c);

#endif
