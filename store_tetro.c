/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_tetro.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 13:59:19 by panderss          #+#    #+#             */
/*   Updated: 2019/12/28 15:24:58 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*new_line(char *file)
{
	char	*tmp;
	int		len;

	len = 0;
	while (file[len] != '\n' && file[len] != '\0')
		len++;
	if (file[len] == '\n')
	{
		*grid = ft_strsub(file, 0, len);
		tmp = ft_strdup(file + len + 1);
		ft_strdel(&file);
		file = tmp;
	}
	else if (file[len] == '\0')
	{
		*grid = ft_strdup(file);
		ft_strdel(&file);
		return (0);
	}
	return (1);
}

int				store_tetro(char *file)
{
	static char	*grid[4];
	char		*line;
	int			ret;
	int			lines_read;

	lines_read = 0;
	while ((ret = new_line(file)) == 0 && lines_read < 4)
	{
		grid[lines_read] = new_line(file, grid);
		lines_read++;
	}
	ft_putendl(grid[0]);/* Lines to display what we have read from the string.*/
	ft_putendl(grid[1]);
	ft_putendl(grid[2]);
	ft_putendl(grid[3]);
	return (0);
}
