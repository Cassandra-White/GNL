

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>
/*
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE
# endif

# define LINE 1
# define END 0
# define ERROR -1
*/
int		get_next_line(int fd, char **line);

int		ft_end(char **line, char **save, int fd, int bytes);
int		ft_line(char **line, char **save, int fd, int i);
int		ft_next_step(char **line, char **save, int fd, int bytes);
size_t		ft_strlen(const char *s1);
char	*ft_malloc_it(size_t size);
int		ft_check_eof(char **line);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);


#endif
