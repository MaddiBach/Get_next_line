#include "get_next_line.h"

static int	ft_strlcpy(char *dst,char *src, int dst_size)
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



	/*
	size_t	i;
	
	i = 0;
	if (!dst && !src)
		return (0);
	while (i < n && src[i])
	{
		*((unsigned char *)dst++) = *((unsigned char *)src++);
		i++;
	}
	(char *)dst[i] = 0;
	*/
}

char	*get_next_line(int fd)
{
	static char	buff[FD_NBR][BUFFER_SIZE + 1];
	char	*line;
	int		readreturn;
	int		endlpos;
	
	line = malloc(1);
	if (fd < 0 || fd > FD_NBR || BUFFER_SIZE <= 0)
			return (NULL);
	while (ft_get_endl(buff[fd]) == -1)
	{

		line = ft_strjoin_to_l(line, buff[fd], 0);
		if (!line)
			return (NULL);
		ft_bzero(buff[fd], BUFFER_SIZE + 1);
		readreturn = read(fd, buff[fd], BUFFER_SIZE);
		if (readreturn <= 0)
		{
			line = ft_strjoin_to_l(line, buff[fd], 1);
			return (line);
		}
	}
	line = ft_strjoin_to_l(line, buff[fd], 0);
	if (!line)
		return (NULL);
	endlpos = ft_get_endl(buff[fd]);
	ft_strlcpy(buff[fd] , buff[fd] + endlpos + 1, BUFFER_SIZE);
	return (line);
}
/*
int main()
{
	int	fd;
	char	*str;

	fd =  open("test.txt", O_RDONLY);
	while ((str = get_next_line(fd)))
	{
		printf("read 2:%s<\n", str);
		free(str);
	}
	printf("read 2:%s<\n", str);
	free(str);
	close (fd);
	return (0);
}
*/