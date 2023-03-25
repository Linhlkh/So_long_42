/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khle <khle@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 08:23:52 by khle              #+#    #+#             */
/*   Updated: 2023/03/21 08:12:28 by khle             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	move_up_c(t_game *game)
{
	game->count_c--;
	game->map_game[game->y][game->x] = 'P';
	if (game->count_e == 0)
	{
		game->map_game[game->y + 1][game->x] = 'E';
		game->count_e++;
	}
	else
		game->map_game[game->y + 1][game->x] = '0';
}

void	move_up_0(t_game *game)
{
	game->map_game[game->y][game->x] = 'P';
	if (game->count_e == 0)
	{
		game->map_game[game->y + 1][game->x] = 'E';
		game->count_e++;
	}
	else
		game->map_game[game->y + 1][game->x] = '0';
}

void	move_up_e(t_game *game)
{
	game->count_e--;
	game->map_game[game->y][game->x] = 'P';
	game->map_game[game->y + 1][game->x] = '0';
	if (game->count_c == 0)
	{
		game->move++;
		ft_putnbr(game->move);
		ft_putchar('\n');
		ft_close(game);
	}
}

void	move_up(t_game *game)
{
	game->y -= 1;
	if (game->map_game[game->y][game->x] != '1')
	{
		if (game->map_game[game->y][game->x] == 'C')
			move_up_c(game);
		else if (game->map_game[game->y][game->x] == '0')
			move_up_0(game);
		else if (game->map_game[game->y][game->x] == 'E')
			move_up_e(game);
		game->move++;
		ft_putnbr(game->move);
		ft_putchar('\n');
	}
}
