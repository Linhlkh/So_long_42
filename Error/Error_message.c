/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khle <khle@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 06:46:04 by khle              #+#    #+#             */
/*   Updated: 2023/03/23 01:28:16 by khle             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	err_des(char *c)
{
	ft_putstr_fd(c, 2);
	ft_putchar_fd('\n', 2);
	exit(1);
}

void	ft_exit(t_game *game, char *msg)
{
	int		i;

	if (game)
	{
		if (game->map_game)
		{
			i = 0;
			while (game->map_game[i])
			{
				free(game->map_game[i]);
				i++;
			}
		}
		free_game(game);
		game = NULL;
	}
	if (msg)
		err_des(msg);
	exit(1);
}

int	free_game(t_game *game)
{
	free(game->map_game);
	if (game->mlx_ptr)
		free(game->mlx_ptr);
	if (game->fd > 2)
		close(game->fd);
	// free(game);
	return (1);
}

int	ft_close(t_game *game)
{
	ft_clean_mlx(game);
	ft_exit (game, NULL);
	return (0);
}
