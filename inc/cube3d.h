/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozone <ozone@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:25:15 by ozone             #+#    #+#             */
/*   Updated: 2024/02/07 15:18:59 by ozone            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "get_next_line.h"
# include "../minilibx-linux/mlx.h"
# include <math.h>
# include <time.h>
# include <unistd.h>
# include <time.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <ctype.h>
# include <string.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>
# include <sys/mman.h>
# include <X11/Xlib.h>
# include <X11/Xutil.h>
# include <sys/ipc.h>
# include <sys/shm.h>
# include <X11/extensions/XShm.h>
# include <X11/XKBlib.h>

# define WIN_X	1080
# define WIN_Y	720
# define FOV	0.66
# define MOVE_SPEED	0.05
# define ENEMY_MOVE_SPEED 0.05;
# define ROT_SPEED	0.05
# define TEXT_SIZE	256
# define MINI_MAP_SIZE	20
# define MINI_MAP_COEF_LEN	12
# define SENSIVITY 1000

typedef struct s_img
{
	void	*img_ptr;
	char	*img_pixels;
	int		bits_pix;
	int		endian;
	int		len;
}	t_img;

typedef struct s_textures_path
{
	char			*NO;
	char			*SO;
	char			*WE;
	char			*EA;
	char			*DO;
	unsigned int	F;
	unsigned int	C;
}	t_textures_path;

typedef struct s_map
{
	char			*map_line;
	struct s_map	*next;
}	t_map;

typedef struct s_pos
{
	char	c;
	double	p_x;
	double	p_y;
	double	dir_camX;
	double	dir_camY;
	double	norm_camX;
	double	norm_camY;
	double	angle;
}	t_pos;

typedef struct s_mouse
{
	int		origin_x;
	int		origin_y;
	int		move_x;
	int		move_y;
}	t_mousse;

typedef struct s_textures
{
	t_img	NO;
	t_img	SO;
	t_img	WE;
	t_img	EA;
	t_img	DO;
}	t_textures;

typedef struct s_point
{
	int		x;
	int		y;
	int		i;
}t_point;

typedef struct s_enemis
{
	double		enemi_pos_x;
	double		enemi_pos_y;
	int			texture;
}t_enemis;

typedef struct s_data
{
	char			**map;
	int				hardmode;
	int				nb_enemis;
	int				map_width;
	int				map_height;
	int				door;
	double			move_speed;
	int				key_move;
	int				map_lenX;
	int				map_lenY;
	void			*mlx;
	void			*win;
	int				i;
	t_img			img_win;
	t_textures_path	textures_path;
	t_textures		textures;
	t_map			*map_char;
	t_pos			pos;
	t_mousse		mouse;
	t_enemis		*enemi;
}	t_data;

typedef struct s_algo
{
	double	Coef_CamX;
	double	rayDir_actX;
	double	rayDir_actY;
	int		map_posX;
	int		map_posY;
	double	delta_distX;
	double	delta_distY;
	double	dist_temp_rayX;
	double	dist_temp_rayY;
	int		side;
	int		texture;
	double	wall_dist;
	int		x;
	int		start;
	int		end;
}	t_algo;

/*free_all.c*/
/* ************************************************************************** */
void			free_map(char **map);
void			free_list(t_map **map);
void			free_all(t_data *data);

/*init_map.c*/
t_map			*init_map_struct(int fd);
void			remove_newlines(t_data data);
char			**get_map(int fd, t_data *data);
char			**init_map(int fd, t_data *data);

/*debug.c*/
void			print_map(char **map);
void			print_args(t_data *data);

/*lst_function.c*/
void			ft_lstadd_back(t_map **lst, t_map *new);
t_map			*ft_lstlast(t_map *lst);
t_map			*ft_lstnew(void *content);
int				ft_lstsize(t_map *lst);

/*functions_plus*/
int				ft_atoi(const char *nptr);
int				get_args(t_data *data);
size_t			ft_strlen2(char **s);
size_t			ft_strcpy(char *dst, char *src);
char			**trunc_map(t_data *data);
int				check_map_valid(t_data *data);
void			flood_fill(char **tab, t_point *size, t_point *begin, t_data *data);
char			**map_dup(char **tab);
void			change_dis(t_point *dis, t_pos start, t_data *data, int cases);

/*get_vec.c*/
void			get_player_vec_camera(t_data *data);
void			get_fov(char c, t_data *data);
void			get_pos(char c, t_data *data);

/*display.c*/
void			trace_line(t_img *img, t_pos start, t_point dis, int color);
int				take_pix(t_img *img, int x, int y);
int				ft_display(t_data *data);
int				ft_stop(t_data *data);
int				ft_key_check(int key, t_data *data);
int				is_door_valid(char **map, t_data *data);
void			draw_mini_map_pix(t_data *data, int x, int y, t_pos *pos_map);

/*init_img.c*/
void			ft_init_img(t_data *data);

/*build_img.c*/
void			build_img(t_data *data);
int				mouse_move(int x, int y, t_data *data);

/*build_img2.c*/
unsigned int	get_color(unsigned char R, unsigned char G, unsigned char B);
void			img_pixel_put(t_img *img, int x, int y, int color);
void			get_texture(t_algo *algo, int stepX, int stepY);
void			pix_texture(t_data *data, t_algo *algo, int *y);

/*move.c*/
void			ft_move2(t_data *data, int dir);
void			ft_move(t_data *data, int dir);
void			ft_rotation_left(t_data *data);
void			ft_rotation_right(t_data *data);
int				change_fov(int key, t_data *data);

/*mini_map.c*/
void			show_map(t_data *data);
unsigned int	ft_mix_color(int color1, int color2, float pourcent);
int				set_mouse_center_screen(t_data *data);
void			ft_rotation(t_data *data, double rot_coef);

/*maths*/
double			sqr(double nb);
void			put_info_on_screen(t_data *data);
char			*ft_itoa(int n);
void			put_info_on_screen(t_data *data);
void			placing_enemis(t_data *data);
void			enemy_AI(t_data *data);

#endif