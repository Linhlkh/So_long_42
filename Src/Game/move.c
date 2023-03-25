/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khle <khle@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 08:25:22 by khle              #+#    #+#             */
/*   Updated: 2023/03/22 15:48:44 by khle             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	count_c_e(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->map_game[x])
	{
		y = 0;
		while (game->map_game[x][y])
		{
			if (game->map_game[x][y] == 'C')
				game->count_c++;
			if (game->map_game[x][y] == 'E')
				game->count_e++;
			y++;
		}
		x++;
	}
}

void	pacman_pos(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map_game[i])
	{
		j = 0;
		while (game->map_game[i][j])
		{
			if (game->map_game[i][j] == 'P')
			{
				game->x = j;
				game->y = i;
			}
			j++;
		}
		i++;
	}
}

int	ft_move( int key, t_game *game)
{
	pacman_pos(game);
	if (key == XK_Escape)
		ft_close(game);
	else if (key == XK_w)
		move_up(game);
	else if (key == XK_a)
		move_left(game);
	else if (key == XK_d)
		move_right(game);
	else if (key == XK_s)
		move_down(game);
	return (0);
}
