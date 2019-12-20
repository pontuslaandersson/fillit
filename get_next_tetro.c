#include "get_next_line.h"

char	*get_next_tetro(int fd, char *tetro)

static int	new_line(char **s, char **line, int fd)
{
	char	*tmp;
	int		len;

	len = 0;
	while (s[fd][len] != '\0')
		len++;
	else if (s[fd][len] == '\0')
	{
		*line = ft_strdup(s[fd]);
		ft_strdel(&s[fd]);
	}
	return (1);
}

int			get_next_tetro(const int fd, char **line)
{
	static char	*s[FD_MAX];
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	ssize_t		ret;

	if (fd < 0 || line == NULL || fd > FD_MAX)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strnew(0);
		tmp = ft_strjoin(s[fd], buf);
		ft_strdel(&s[fd]);
		s[fd] = tmp;
	}
	if (ret < 0)
		return (-1);
	else if ((ret == 0 && s[fd] == NULL) || s[fd][0] == '\0')
		return (0);
	return (new_line(s, line, fd));
}