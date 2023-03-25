/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khle <khle@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 02:57:20 by khle              #+#    #+#             */
/*   Updated: 2023/03/23 07:22:22 by khle             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	**convert_map_to_chain(int fd)
{
	char	*line;
	char	*chain;
	char	**map;

	line = get_next_line(fd);
	chain = ft_strdup("");
	while (line)
	{
		chain = ft_strjoin(chain, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if ((ft_strstr(chain, "\n\n")) != NULL)
	{
		free(chain);
		err_des("Error: Map invalid");
	}
	map = ft_split(chain, '\n');
	free(chain);
	return (map);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		err_des(ERROR_ARG);
	if (!check_ber(argv[1], ".ber"))
		err_des(ERROR_EXT);
	game_init(& game);
	game.fd = open(argv[1], O_RDONLY);
	if (game.fd == -1)
		ft_exit(& game, ERROR_FILE);
	game.map_game = convert_map_to_chain(game.fd);
	if (!game.map_game)
		ft_exit(& game, NULL);
	if (!ft_map_is_valid(game.map_game))
		ft_close(& game);
	display_game(& game);
	ft_close(& game);
}

// int	main(int argc, char **argv)
// {
// 	t_game	*game;

// 	if (argc != 2)
// 		err_des(ERROR_ARG);
// 	if (!check_ber(argv[1], ".ber"))
// 		err_des(ERROR_EXT);
// 	game = (void *)malloc(sizeof(t_game));
// 	if (!game)
// 		err_des(ERROR_MALLOC);
// 	game_init(game);
// 	game.fd = open(argv[1], O_RDONLY);
// 	if (game->fd == -1)
// 		ft_exit(game, ERROR_FILE);
// 	game->map_game = convert_map_to_chain(game->fd);
// 	if (!game->map_game)
// 		ft_exit(game, NULL);
// 	if (!ft_map_is_valid(game->map_game))
// 		ft_close(game);
// 	display_game(game);
// 	ft_close(game);
// }
