#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 2
# define FD_NBR 256

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	ft_strclen(char *str, char c);
void	ft_bzero(char *str, int n);
int	ft_get_endl(char *str);
char	*ft_strcdup(char *str, char c);
char	*ft_strjoin_to_l(char *line, char *buff, int key);
char    *get_next_line(int fd);
void	*ft_realloc(void *ptr, int size, int newsize);
#endif