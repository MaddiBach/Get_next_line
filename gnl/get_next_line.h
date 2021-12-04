#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 42
# define FD_NBR 300

# include <unistd.h>

int	ft_strclen(char *str, char c);
void	ft_bzero(char *str, int n);
int	ft_get_endl(char *str);
char	*ft_strcdup(char *str, char c);
char	*ft_strjoin_to_l(char *line, char *buff);

#endif