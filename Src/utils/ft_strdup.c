/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khle <khle@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 03:50:02 by khle              #+#    #+#             */
/*   Updated: 2023/03/23 02:40:32 by khle             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

char	*ft_strdup(char *str1)
{
	char	*str2;
	int		i;

	i = 0;
	while (!str1)
		return (0);
	str2 = (char *)malloc(sizeof (*str1) * (ft_strlen(str1) + 1));
	if (!str2)
		return (NULL);
	while (str1[i] && str1[i] != '\n')
	{
		str2[i] = str1[i];
		i++;
	}
	str2[i] = 0;
	return (str2);
}
