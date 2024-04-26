/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmartin <bmartin@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:31:36 by bmartin           #+#    #+#             */
/*   Updated: 2023/05/04 17:09:58 by bmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../MLX42/include/GLFW/glfw3.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/ft_printf/ft_printf.h"
# include "../libft/gnl/get_next_line.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define IMG_PIXEL_SIZE 64

//message erreur
# define E_CHAR_INVALID "Error\n Found Invalid Character\n"
# define E_CHAR_MISSING "Error\n Mandatory Character Count Wrong\n"
# define E_MAP_TOO_WIDTH "Error\n Map Too Wide (Max 40)\n"
# define E_MAP_TOO_HEIGTH "Error\n Map Too High (max 21)\n"
# define E_MAP_LINE_DIFF "Error\n Lines Are Not Egal Length On Map\n"
# define E_MAP_BORDER "Error\n Map Border Missing\n"
# define E_FILE_NAME "Error\n File Name Is Invalid\n"
# define E_FLOODFILL "Error\n Floodfill Is Invalid\n"
# define E_ARGS_NUM "Error\n Argument Number is wrong\n"
# define E_FD_WRONG "Error:\n fd Error read value WRONG\n"

typedef struct s_data
{
	mlx_t			*mlx;

	int				width;
	int				height;
	char			*all_char_map;
	int				width_pixel;
	int				height_pixel;
	char			**map;
	char			**tmp_map;
	int				player_position_x;
	int				player_position_y;
	int				tmp_player_position_x;
	int				tmp_player_position_y;
	int				collectable_count;
	int				collectable_left;
	int				move_counter;
	int				direction;
	int				flag_exit;
	int				exit_x;
	int				exit_y;
	int				map_y;
	char			*stash;
	char			*char_map;
	int				i;
	int				e;
	int				p;
	int				c;
	int				x;
	int				y;

	mlx_texture_t	*wall;
	mlx_texture_t	*grass;
	mlx_texture_t	*collectable;
	mlx_texture_t	*collectable_shine;
	mlx_texture_t	*penguin_idle;
	mlx_texture_t	*penguin_idle2;
	mlx_texture_t	*penguin_walk_right;
	mlx_texture_t	*penguin_walk_right2;
	mlx_texture_t	*penguin_walk_left;
	mlx_texture_t	*penguin_walk_left2;
	mlx_texture_t	*penguin_walk_up;
	mlx_texture_t	*penguin_walk_up2;
	mlx_texture_t	*penguin_walk_down;
	mlx_texture_t	*penguin_walk_down2;
	mlx_texture_t	*sun;
	mlx_texture_t	*sun2;
	mlx_texture_t	*exit;

	mlx_image_t		*wall_img;
	mlx_image_t		*grass_img;
	mlx_image_t		*collectable_img;
	mlx_image_t		*collectable_shine_img;
	mlx_image_t		*penguin_idle_img;
	mlx_image_t		*penguin_idle2_img;
	mlx_image_t		*penguin_walk_right_img;
	mlx_image_t		*penguin_walk_right2_img;
	mlx_image_t		*penguin_walk_left_img;
	mlx_image_t		*penguin_walk_left2_img;
	mlx_image_t		*sun_img;
	mlx_image_t		*sun2_img;
	mlx_image_t		*exit_img;

}					t_data;

t_data				*get_data(void);

//function

void				map_load(int argc, char *argv[]);
void				ber_to_string(int argc, char *argv[]);
void				get_map_height(int argc, char *argv[]);
void				get_map_width(void);
void				string_to_2d_map(void);
void				map_valid(void);
void				map_valid_length(void);
void				map_valid_char(void);
void				map_valid_char_count(void);
void				map_valid_line_length(void);
void				map_valid_border(void);
void				print_error_exit(void);
void				img_init(void);
void				png_to_texture(void);
void				texture_to_image(void);
void				render(void);
void				render_moving_asset(int x, int y);
void				player_position(int x, int y);
void				render_exit(int x, int y);
void				my_key_hook(mlx_key_data_t keydata, void *param);
void				collectable_left(t_data *var);
void				animation_choose(void);
void				animation_up(void);
void				animation_left(void);
void				animation_right(void);
void				animation_down(void);
void				check_map_extension(char *argv);
void				print_map_name_error(void);
void				release(void **tab);
void				str_move(void);
void				win(void);
void				get_tmp_value(void);
int					floodfill(int x, int y, t_data *var);
char				**strdup_2d(char **str, int height);
void				print_no_floodfill(void);
void				print_argc_error(void);
void				print_fd_wrong(void);

#endif
