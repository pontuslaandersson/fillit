/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 12:43:01 by panderss          #+#    #+#             */
/*   Updated: 2019/12/11 13:30:06 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *src, size_t n)
{
	char	*duplicate;
	int		index;

	index = 0;
	while (src[index])
		index++;
	if (!(duplicate = (char *)malloc(sizeof(char) * (index + 1))))
		return (NULL);
	index = -1;
	while (src[++index] && n > 0)
	{
		duplicate[index] = src[index];
		n--;
	}
	duplicate[index] = '\0';
	return (duplicate);
}
