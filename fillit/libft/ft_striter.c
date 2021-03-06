/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 14:20:05 by panderss          #+#    #+#             */
/*   Updated: 2019/12/11 13:24:47 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *str, void (*f)(char *))
{
	if (str && f)
	{
		while (*str != '\0')
			f(str++);
	}
}
