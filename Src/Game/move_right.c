/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khle <khle@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 08:25:30 by khle              #+#    #+#             */
/*   Updated: 2023/03/21 08:12:51 by khle             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	move_right_c(t_game *game)
{
	game->count_c--;
	game->map_game[game->y][game->x] = 'P';
	if (game->count_e == 0)
	{
		game->map_game[game->y][game->x - 1] = 'E';
		game->count_e++;
	}
	else
		game->map_game[game->y][game->x - 1] = '0';
}

void	move_right_0(t_game *game)
{
	game->map_game[game->y][game->x] = 'P';
	if (game->count_e == 0)
	{
		game->map_game[game->y][game->x - 1] = 'E';
		game->count_e++;
	}
	else
		game->map_game[game->y][game->x - 1] = '0';
}

void	move_right_e(t_game *game)
{
	game->count_e--;
	game->map_game[game->y][game->x] = 'P';
	game->map_game[game->y][game->x - 1] = '0';
	if (game->count_c == 0)
	{
		game->move++;
		ft_putnbr(game->move);
		ft_putchar('\n');
		ft_close(game);
	}
}

void	move_right(t_game *game)
{
	game->x += 1;
	if (game->map_game[game->y][game->x] != '1')
	{
		if (game->map_game[game->y][game->x] == 'C')
			move_right_c(game);
		else if (game->map_game[game->y][game->x] == '0')
			move_right_0(game);
		else if (game->map_game[game->y][game->x] == 'E')
			move_right_e(game);
		game->move++;
		ft_putnbr(game->move);
		ft_putchar('\n');
	}
}
