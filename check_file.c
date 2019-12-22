/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 14:17:12 by panderss          #+#    #+#             */
/*   Updated: 2019/12/18 14:41:47 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *get_file(int fd, char *line)
{
    static char *str;

    while ((ret = get_next_line(fd, &line)) > 0)
    {
        /*strjoin return of GNL, and _keep newlines_*/
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
