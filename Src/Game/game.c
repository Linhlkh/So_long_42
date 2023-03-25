/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khle <khle@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 20:38:47 by khle              #+#    #+#             */
/*   Updated: 2023/03/22 16:20:47 by khle             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	img_to_win(t_game *game, int x, int y)
{
	if (game->map_game[y][x] == '1')
		mlx_put_image_to_window(game->mlx_ptr,
			game->win_ptr, game->img_wall, x * 50, y * 50);
	if (game->map_game[y][x] == '0')
		mlx_put_image_to_window(game->mlx_ptr,
			game->win_ptr, game->img_road, x * 50, y * 50);
	if (game->map_game[y][x] == 'P')
		mlx_put_image_to_window(game->mlx_ptr,
			game->win_ptr, game->img_pacman, x * 50, y * 50);
	if (game->map_game[y][x] == 'E')
		mlx_put_image_to_window(game->mlx_ptr,
			game->win_ptr, game->img_exit, x * 50, y * 50);
	if (game->map_game[y][x] == 'C')
		mlx_put_image_to_window(game->mlx_ptr,
			game->win_ptr, game->img_coin, x * 50, y * 50);
}

int	put_all_img_to_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map_game[y])
	{
		x = 0;
		while (game->map_game[y][x])
		{
			img_to_win(game, x, y);
			x++;
		}
		y++;
	}
	return (0);
}

void	mlx_display_game(t_game *game)
{
	mlx_hook(game->win_ptr, 2, 1L << 0, ft_move, game);
	mlx_hook(game->win_ptr, 17, (1L << 17), ft_close, game);
	mlx_loop_hook(game->mlx_ptr, put_all_img_to_map, game);
	mlx_loop(game->mlx_ptr);
}

void	display_game(t_game *game)
{
	int	x;
	int	y;
	int	length;
	int	width;

	x = ft_strlen(game->map_game[0]);
	y = ft_len_tab(game->map_game);
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		ft_close(game);
	mlx_get_screen_size(game->mlx_ptr, &length, &width);
	if (length < x * 50 || width < y * 50)
	{
		ft_clean_mlx(game);
		ft_exit(game, ERROR_SCREEN_SIZE);
	}
	game->win_ptr = mlx_new_window(game->mlx_ptr, x * 50,
			y * 50, "SO LONG");
	if (!game->win_ptr)
		ft_close(game);
	image_init(game);
	put_all_img_to_map(game);
	count_c_e(game);
	mlx_display_game(game);
}
