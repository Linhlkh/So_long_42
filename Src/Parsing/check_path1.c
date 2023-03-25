/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khle <khle@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 03:03:15 by khle              #+#    #+#             */
/*   Updated: 2023/03/15 07:07:11 by khle             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	p_up(char **map, t_count *count, t_coord *coor, char c)
{
	map[coor->y - 1][coor->x] = 'P';
	if (c == 'C')
		count->c--;
	if (c == 'E')
		count->e--;
}

void	p_down(char **map, t_count *count, t_coord *coor, char c)
{
	map[coor->y + 1][coor->x] = 'P';
	if (c == 'C')
		count->c--;
	if (c == 'E')
		count->e--;
}

void	p_left(char **map, t_count *count, t_coord *coor, char c)
{
	map[coor->y][coor->x - 1] = 'P';
	if (c == 'C')
		count->c--;
	if (c == 'E')
		count->e--;
}

void	p_right(char **map, t_count *count, t_coord *coor, char c)
{
	map[coor->y][coor->x + 1] = 'P';
	if (c == 'C')
		count->c--;
	if (c == 'E')
		count->e--;
}

int	charset_to_p(char **map, t_count *count, t_coord *coor, char c)
{
	int	temp;

	temp = 0;
	if (map[coor->y - 1][coor->x] == c)
	{
		p_up(map, count, coor, c);
		temp++;
	}
	if (map[coor->y + 1][coor->x] == c)
	{
		p_down(map, count, coor, c);
		temp++;
	}
	if (map[coor->y][coor->x - 1] == c)
	{
		p_left(map, count, coor, c);
		temp++;
	}
	if (map[coor->y][coor->x + 1] == c)
	{
		p_right(map, count, coor, c);
		temp++;
	}
	return (temp);
}
