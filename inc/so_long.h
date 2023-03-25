/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khle <khle@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 06:50:33 by khle              #+#    #+#             */
/*   Updated: 2023/03/23 06:52:37 by khle             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// return 1: success
// return 0: fail

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include "../mlx/mlx.h"
# include <X11/keysym.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# define ERROR_ARG "Error: Number of argument invalid \
([./so_long] [path_map.ber])"
# define ERROR_EXT "Error: File name invalid"
# define ERROR_FILE "Error: Cannot open the file"
# define ERROR_MALLOC "Error: Malloc fail"
# define ERROR_EMPTY "Error: Map is empty"
# define ERROR_REC "Error: Map is not rectangle"
# define ERROR_CHAR "Error: Char invalid"
# define ERROR_WALL "Error: Wall invalid"
# define ERROR_PATH "Error: Path invalid"
# define ERROR_SCREEN_SIZE  "Error: the map is too big for the screen"

typedef struct s_count
{
	int	p;
	int	e;
	int	c;
}			t_count;

typedef struct s_coord
{
	int	y;
	int	x;	
}			t_coord;

typedef struct s_game
{
	char	**map_game;
	int		x;
	int		y;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	void	*img_wall;
	void	*img_road;
	void	*img_coin;
	void	*img_pacman;
	void	*img_exit;
	int		count_e;
	int		count_c;
	int		move;
	int		fd;
}			t_game;


/******************************************************************************/
/*									PARSING	  								  */
/******************************************************************************/

int			check_ber(char *str1, char *str2);
int			check_valid_char(char c);
int			check_valid_char_map(char **str);
int			check_rectangle(char **map);

int			check_wall_line1(char *map_line);
int			check_wall_line2(char *map_line);
int			check_wall_map(char **map);
int			count_map(char **map, t_count *count_set);

void		p_up(char **map, t_count *count, t_coord *coor, char c);
void		p_down(char **map, t_count *count, t_coord *coor, char c);
void		p_left(char **map, t_count *count, t_coord *coor, char c);
void		p_right(char **map, t_count *count, t_coord *coor, char c);
int			charset_to_p(char **map, t_count *count, t_coord *coor, char c);

int			total_temp(char **map, t_count *count, t_coord *coor);
int			change_to_p(char **map, t_count *count);
int			check_valid_path(char **map, t_count *count);
int			ft_map_is_valid(char **map);

char		**convert_map_to_chain(int fd);



/******************************************************************************/
/*									UTILS	  								  */
/******************************************************************************/

void		ft_putnbr(int nb);
void		ft_putchar(char c);
char		*ft_strdup(char *str1);
int			ft_len_tab(char **s);
char		*ft_strchr(char *s, char c);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_get_line(char *buff);
char		*ft_get_rest(char *buff);
char		*ft_get_buff(int fd, char *buff);
char		*get_next_line(int fd);
int			ft_strlen(char *str);
char		**ft_split(char *s, char c);
void		ft_putstr(char *s);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
char		**copy_map(char	**map);
void		ft_free_double_tab(char **tab);
char		*ft_strstr(char *str, char *to_find);

/******************************************************************************/
/*									ERRORS  								  */
/******************************************************************************/

void		err_des(char *c);
int			ft_clean_mlx(t_game *game);
void		ft_exit(t_game *game, char *msg);
int			free_game(t_game *game);
int			ft_close(t_game *game);


/******************************************************************************/
/*									GAME	  								  */
/******************************************************************************/

void		count_c_e(t_game *game);
void		pacman_pos(t_game *game);
void		*xpm_to_image(char *filename, t_game *game);
void		image_init(t_game *game);
void		move_down(t_game *game);
void		move_left(t_game *game);
void		move_right(t_game *game);
void		move_up(t_game *game);
int			ft_move( int key, t_game *game);
void		game_init(t_game *game);
void		img_to_win(t_game *game, int x, int y);
int			put_all_img_to_map(t_game *game);
void		mlx_display_game(t_game *game);
void		display_game(t_game *game);
void		image_init(t_game *game);
void		count_c_e(t_game *game);
void		pacman_pos(t_game *game);
int			ft_move( int key, t_game *game);

#endif