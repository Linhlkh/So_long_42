/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khle <khle@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 07:25:45 by khle              #+#    #+#             */
/*   Updated: 2023/03/22 07:28:48 by khle             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_clean_mlx(t_game *game)
{
	if (game->mlx_ptr)
		mlx_loop_end(game->mlx_ptr);
	if (game->mlx_ptr && game->img_coin)
		mlx_destroy_image(game->mlx_ptr, game->img_coin);
	if (game->mlx_ptr && game->img_exit)
		mlx_destroy_image(game->mlx_ptr, game->img_exit);
	if (game->mlx_ptr && game->img_road)
		mlx_destroy_image(game->mlx_ptr, game->img_road);
	if (game->mlx_ptr && game->img_pacman)
		mlx_destroy_image(game->mlx_ptr, game->img_pacman);
	if (game->mlx_ptr && game->img_wall)
		mlx_destroy_image(game->mlx_ptr, game->img_wall);
	if (game->mlx_ptr && game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
		mlx_destroy_display(game->mlx_ptr);
	return (0);
}
