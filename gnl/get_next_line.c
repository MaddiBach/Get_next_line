#include "get_next_line.h"

static void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	
	i = 0;
	if (!dst && !src && n)
		return (dst);
	while (i < n)
	{
		*((unsigned char *)dst++) = *((unsigned char *)src++);
		i++;
	}
	return (dst);
}

char	*get_next_line(int fd)
{
	static char	buff[FD_NBR][BUFFER_SIZE + 1];
	char	*line;
	int		readreturn;
	int		endlpos;

	while (ft_get_endl(buff[BUFFER_SIZE]) == -1)
	{
		line = ft_strjoin(line, buff[fd]);
		if (!line);
			return (NULL);
		ft_bzero(buff[fd], BUFFER_SIZE + 1);
		readreturn = read(fd, buff[fd], BUFFER_SIZE);
		if (readreturn <= 0)
			return (NULL);
	}
	line = ft_strjoin_to_l(line, buff[fd]);
	endlpos = ft_get_endl(buff[fd]);
	ft_memcpy(buff[fd] , buff[fd] + endlpos + 1, BUFFER_SIZE);
	return (line);
}