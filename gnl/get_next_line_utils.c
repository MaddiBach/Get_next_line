#include "get_next_line.h";

int	ft_strclen(char *str, char c)
{
	int	i;
	if (!str)
		return (NULL);
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
	while(str[i])
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
	dup = malloc(sizeof(char) * (ft_strlen_to_c(str, c) + 1));
	if (dup == NULL)
		return (NULL);
	while (*str && *str != c)
		*dup++ = *str++;
	if (*str = c)
		*dup++ = *str++;
	*dup = '\0';
//	if (str)
//		free(str);
	return (dup);
}

char	*ft_strjoin_to_l(char *line, char *buff)
{
	char	*ret;
	int		i;

	i = 0;
	if (!line)
		return (ft_strdup_to_c(buff, '\n'));
	ret = malloc(sizeof(char) * (ft_strlen_to_c(buff, '\n') + ft_strlen_to_c(line, '\0') + 1));
	if (ret == NULL)
		return (NULL);
	while (*line)
		ret[i++] = *line++;
	while (*buff && *buff != '\n')
		ret[i++] = *buff++;
	ret[i] = '\0';
	if (line)
		free(line);
	return (ret);
}