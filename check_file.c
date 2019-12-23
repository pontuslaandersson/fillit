/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 14:17:12 by panderss          #+#    #+#             */
/*   Updated: 2019/12/23 14:13:42 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_Line.h"

char    *get_file(int fd)
{
    static char *str;
	char		buf[BUFF_SIZE + 1];

    while ((ret = read(fd, buf, BUF_SIZE)) > 0)
    {
		buf[ret] = '\0';
		if (str == NULL)
			str = ft_strnew(0);
		tmp = ft_strjoin(str, buf);
		ft_strdel(&s);
		s = tmp;
	}
	if (ret < 0)
		return (NULL);
	else if (ret == 0)
	{
		ft_putendl("String read into str:");
		ft_putstr(str);
		return (str);
	}
}

int     check_file(char *file)
{
    int i;
    int newline;

    while (file[i] != '\0')
    {
      if (file[i] == '\n')
            ++newline;
        if (file[i] != '\n' && file[i] != '.' && file[i] != '#')
            return (-1);
        ++i;
    }
    if ((newline - 4) % 5 != 0 || (i - 20) % 21 != 0)
        return (-i);
    else
        return (i);
}
