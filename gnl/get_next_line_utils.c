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

void	*ft_realloc(void *ptr, int size, int newsize)
{
	char	*tmp;
	char	*new;
	int		i;

	tmp = (char *)ptr;
	new = malloc(sizeof(char) * (newsize + 1));
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
	if (ptr)
	{
		*(char *)ptr = 0;
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

int	ft_strlcpy(char *dst,char *src, int dst_size)
{
	int i = 0;
	if (!dst || !src)
		return (0);
	if (dst_size == 0)
		return (ft_strclen(src, 0));
	while (i < (dst_size - 1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (ft_strclen(src, 0));
}
