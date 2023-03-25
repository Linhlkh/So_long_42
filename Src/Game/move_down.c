/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khle <khle@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 08:22:39 by khle              #+#    #+#             */
/*   Updated: 2023/03/21 08:11:59 by khle             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	move_down_c(t_game *game)
{
	game->count_c--;
	game->map_game[game->y][game->x] = 'P';
	if (game->count_e == 0)
	{
		game->map_game[game->y - 1][game->x] = 'E';
		game->count_e++;
	}
	else
		game->map_game[game->y - 1][game->x] = '0';
}

void	move_down_0(t_game *game)
{
	game->map_game[game->y][game->x] = 'P';
	if (game->count_e == 0)
	{
		game->map_game[game->y - 1][game->x] = 'E';
		game->count_e++;
	}
	else
		game->map_game[game->y - 1][game->x] = '0';
}

void	move_down_e(t_game *game)
{
	game->count_e--;
	game->map_game[game->y][game->x] = 'P';
	game->map_game[game->y - 1][game->x] = '0';
	if (game->count_c == 0)
	{
		game->move++;
		ft_putnbr(game->move);
		ft_putchar('\n');
		ft_close(game);
	}
}

void	move_down(t_game *game)
{
	game->y += 1;
	if (game->map_game[game->y][game->x] != '1')
	{
		if (game->map_game[game->y][game->x] == 'C')
			move_down_c(game);
		else if (game->map_game[game->y][game->x] == '0')
			move_down_0(game);
		else if (game->map_game[game->y][game->x] == 'E')
			move_down_e(game);
		game->move++;
		ft_putnbr(game->move);
		ft_putchar('\n');
	}
}
