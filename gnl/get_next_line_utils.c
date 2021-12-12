#include "get_next_line.h"

int	ft_strclen(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != c)
	{
		i++;
	}
	return (i);
}

void	ft_bzero(char *str, int n)
{
	int i;

	i = 0;
	while(str[i] && i < n)
	{
		str[i] = 0;
		i++;
	}
}

int	ft_get_endl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strcdup(char *str, char c)
{
	char	*dup;

	if (!str)
		return (NULL);
	dup = malloc(sizeof(char) * (ft_strclen(str, c) + 1));
	if (dup == NULL)
		return (NULL);
	while (*str && *str != c)
		*dup++ = *str++;
	if (*str == c)
		*dup++ = *str++;
	*dup = '\0';
	if (str)
		free(str);
	return (dup);
}
/*
void	*ft_realloc(void *ptr, int size, int newsize)
{
	char	*str;
	char	*new;
	int		i;

	str = (char*)ptr;
	if (!(new = (char*)malloc(sizeof(char) * newsize + 1)))
	{
		if (ptr && size != 0)
			free(ptr);
		return (NULL);
	}
	i = -1;
	while (++i < size)
		*(new + i) = *(str + i);
	while (i < newsize)
		*(new + i++) = '\0';
	if (ptr && size != 0)
		free(ptr);
	return (new);
}*/


void	*ft_realloc(void *ptr, int size, int newsize)
{
	char	*tmp;
	char	*new;
	int		i;

	tmp = (char *)ptr;
	new = malloc(sizeof(char) * (newsize) + 1);
	if (new == NULL)
	{
		if (ptr && size != 0)
			free(ptr);
		return (NULL);
	}
	i = 0;
	while (i <= size)
	{
		new[i] = tmp[i];
		i++;
	}
	while (i < newsize)
		new[i++] = 0;
	if (ptr && size != 0)
	{
		ft_bzero(ptr, size);
		free(ptr);
	}
	return (new);
}

char	*ft_strjoin_to_l(char *line, char *buff, int key)
{
	char	*ret;
	int		i;

	i = 0;
	if (*line == 0 && *buff == 0 && key == 1)
	{
		free(line);
		return (NULL);
	}
	if (!line || !buff)
		return (NULL);
	key = key +1;
	ret = ft_realloc(line, ft_strclen(line, '\n'), (ft_strclen(line, '\n') + ft_strclen(buff, '\n')));
	if (ret == NULL)
		return (NULL);
	while (ret[i])
		i++;
	while (*buff && *buff != '\n')
		ret[i++] = *buff++;
	if (*buff == '\n')
		ret[i++] = '\n';
	ret[i] = '\0';

	return (ret);
}
