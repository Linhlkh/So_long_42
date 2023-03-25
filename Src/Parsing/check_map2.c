/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khle <khle@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 01:59:12 by khle              #+#    #+#             */
/*   Updated: 2023/03/23 05:47:15 by khle             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	check_wall_line1(char *map_line)
{
	int	i;

	i = 0;
	if (!map_line)
		return (0);
	while (map_line[i])
	{
		if (map_line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_wall_line2(char *map_line)
{
	int	i;

	if (!map_line)
		return (0);
	i = ft_strlen(map_line);
	if (map_line[0] == '1' && map_line[i - 1] == '1')
		return (1);
	return (0);
}

int	check_wall_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return (0);
	// if (!*map)
	// 	return (free(map), 0);
	while (map[i] && map[i + 1])
	{
		if (check_wall_line2(map[i]) == 0)
			return (0);
		i++;
	}
	if (check_wall_line1(map[0]) == 0 || check_wall_line1(map[i]) == 0)
		return (0);
	return (1);
}

int	count_map(char **map, t_count *count_set)
{
	int	x;
	int	y;

	x = 0;
	if (!map)
		return (0);
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if ((map[x][y]) == 'P')
				count_set->p += 1;
			if ((map[x][y]) == 'E')
				count_set->e += 1;
			if ((map[x][y]) == 'C')
				count_set->c += 1;
			y++;
		}
		x++;
	}
	if (count_set->p != 1 || count_set->e != 1 || count_set->c <= 0)
		return (0);
	return (1);
}

/*int main()
{

	char *str[] = {"CP111", "1rEs1", "1Pme1", "C11"};
	t_count dem;
	int a;
	a = 0;
	dem.p = 0;
	dem.e = 0;
	dem.c = 0;
	int i = count_map(str, dem);
	printf ("%i\n", i);
	printf("c:%i\ne:%i\np:%i\n", dem.c, dem.e, dem.p);
}*/
/*int main()
{

	char *str[] = {"11111", "1res1", "1ome1", "111"};
	printf ("%i", check_wall_map(str));
}*/
