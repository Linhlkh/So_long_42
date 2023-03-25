/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khle <khle@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 01:01:31 by khle              #+#    #+#             */
/*   Updated: 2023/03/23 01:30:16 by khle             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	total_temp(char **map, t_count *count, t_coord *coor)
{
	int	temp;

	temp = 0;
	temp += charset_to_p(map, count, coor, 'C');
	temp += charset_to_p(map, count, coor, '0');
	temp += charset_to_p(map, count, coor, 'E');
	if (temp == 0)
		return (0);
	return (1);
}

int	change_to_p(char **map, t_count *count)
{
	int		temp;
	t_coord	coor;

	temp = 0;
	coor.y = 0;
	while (map[coor.y])
	{
		coor.x = 0;
		while (map[coor.y][coor.x])
		{
			if (map[coor.y][coor.x] == 'P')
				temp += total_temp(map, count, &coor);
			coor.x++;
		}
		coor.y++;
	}
	return (temp);
}

static int	valid_map(t_count *count)
{
	if (count->c == 0 && count->e == 0)
		return (0);
	return (1);
}

int	check_valid_path(char **map, t_count *count)
{
	int		temp;
	char	**copy_char;

	temp = 0;
	copy_char = copy_map(map);
	while (valid_map(count))
	{
		temp = change_to_p(copy_char, count);
		if (temp == 0)
		{
			ft_free_double_tab(copy_char);
			return (0);
		}
		else
			temp = 0;
	}
	ft_free_double_tab(copy_char);
	return (1);
}

int	ft_map_is_valid(char **map)
{
	t_count	count;

	count.c = 0;
	count.e = 0;
	count.p = 0;
	if (!map)
		err_des(ERROR_EMPTY);
	if (!check_rectangle(map))
	{
		ft_free_double_tab(map);	
		err_des(ERROR_REC);
	}
	if (!check_wall_map(map))
	{
		ft_free_double_tab(map);	
		err_des(ERROR_WALL);
	}
	if (!check_valid_char_map(map))
	{
		ft_free_double_tab(map);	
		err_des(ERROR_CHAR);
	}
	if (!count_map(map, &count))
	{
		ft_free_double_tab(map);	
		err_des(ERROR_CHAR);
	}
	if (!check_valid_path(map, &count))
	{
		ft_free_double_tab(map);	
		err_des(ERROR_PATH);
	}
	return (1);
}

// int main()
// {
// 	int fd;
// 	fd = open("./map/map1.ber", O_RDONLY);
// 	char **map;
// 	map = convert_map_to_chain(fd);
// 	t_count	count;

// 	count.c = 0;
// 	count.e = 0;
// 	count.p = 0;
// 	printf("%i\n",count_map(map, &count));
// 	printf("%i", check_valid_path(map, &count));
// }