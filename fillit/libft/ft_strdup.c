/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:14:49 by panderss          #+#    #+#             */
/*   Updated: 2019/12/11 13:21:55 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*duplicate;
	int		index;

	index = 0;
	while (src[index])
		index++;
	if (!(duplicate = (char *)malloc(sizeof(char) * (index + 1))))
		return (NULL);
	index = -1;
	while (src[++index])
		duplicate[index] = src[index];
	duplicate[index] = '\0';
	return (duplicate);
}
