/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khle <khle@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 05:17:43 by khle              #+#    #+#             */
/*   Updated: 2023/03/22 16:31:31 by khle             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	check_ber(char *str1, char *str2)
{
	int	i;
	int	j;

	i = ft_strlen(str1) - 1;
	j = ft_strlen(str2) - 1;
	while (j >= 0)
	{
		if (str1[i] == str2[j])
		{
			i--;
			j--;
		}
		else
			return (0);
	}
	return (1);
}

int	check_valid_char(char c)
{
	if (c == 'P' || c == 'C' || c == '1' || c == '0' || c == 'E')
		return (1);
	return (0);
}

int	check_valid_char_map(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str && str[i])
	{
		while (str[i][j])
		{
			if (check_valid_char(str[i][j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_rectangle(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return (0);
	while (map[i] && map[i + 1])
	{
		if (ft_strlen(map[i]) != ft_strlen(map[i + 1]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}


/*int main()
{

	char *str[] = {"These", "aress", "somes", "strin"};
	printf ("%i", check_rectangle(str));
}*/
