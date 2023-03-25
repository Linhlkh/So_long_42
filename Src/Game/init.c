/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khle <khle@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 03:28:23 by khle              #+#    #+#             */
/*   Updated: 2023/03/22 16:02:04 by khle             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	*xpm_to_image(char *filename, t_game *game)
{
	int		width;
	int		hight;
	void	*img_ptr;

	width = 50;
	hight = 50;
	img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, filename, &width, &hight);
	if (!img_ptr)
		ft_close(game);
	return (img_ptr);
}

void	image_init(t_game *game)
{
	game->img_wall = xpm_to_image("./Src/img_xpm/wall.xpm", game);
	game->img_exit = xpm_to_image("./Src/img_xpm/exit.xpm", game);
	game->img_coin = xpm_to_image("./Src/img_xpm/coin.xpm", game);
	game->img_road = xpm_to_image("./Src/img_xpm/road.xpm", game);
	game->img_pacman = xpm_to_image("./Src/img_xpm/pacman.xpm", game);
}

void	game_init(t_game *game)
{
	game->map_game = NULL;
	game->mlx_ptr = NULL;
	game->img = NULL;
	game->win_ptr = NULL;
	game->img_coin = 0;
	game->img_exit = 0;
	game->img_road = 0;
	game->img_pacman = 0;
	game->img_wall = 0;
	game->count_c = 0;
	game->count_e = 0;
	game->move = 0;
}
