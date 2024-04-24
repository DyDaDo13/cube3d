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
# include <sys/time.h>

# define WIN_X				1080
# define FULLIFE			5
# define WIN_Y				720
# define FOV				0.66
# define MOVE_SPEED			0.02
# define ENEMY_MOVE_SPEED	0.02
# define HITBOX				1
# define ROT_SPEED			0.1
# define TEXT_SIZE			256
# define MINI_MAP_SIZE		20
# define MINI_MAP_COEF_LEN	12
# define SENSIVITY			1000
# define TIME_ACT_TEXT		25
# define NB_TEXT_SPRITE		4

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
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*dor;
	unsigned int	f;
	unsigned int	c;
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
	double	dir_camx;
	double	dir_camy;
	double	norm_camx;
	double	norm_camy;
	double	angle;
}	t_pos;

typedef struct s_mouse
{
	int		origin_x;
	int		origin_y;
	int		move_x;
	int		move_y;
	int		mouse_lock;
}	t_mousse;

typedef struct s_textures
{
	t_img	no;
	t_img	so;
	t_img	we;
	t_img	ea;
	t_img	dor;
	t_img	enemy1;
	t_img	enemy2;
	t_img	enemy3;
	t_img	enemy4;
	t_img	enemy1_d;
	t_img	pov;
	t_img	heart_full;
	t_img	heart_empty;
	t_img	shoot_pov;
	int		add_pov;
	int		way_pov;
	int		tex_pov;
}	t_textures;

typedef struct s_info
{
	int		fov;
	int		live_ennemy;
	double	sensivity;
	double	speed;
	double	fps;
	double	temp;
}	t_info;

typedef struct s_point
{
	int		x;
	int		y;
	int		i;
	int		j;
	int		d;
}	t_point;

typedef struct s_enemy
{
	double		x;
	double		y;
	int			texture;
	int			act_text;
}	t_enemy;

typedef struct s_data
{
	char			**map;
	int				hardmode;
	int				nb_enemy;
	int				map_width;
	int				map_height;
	int				pv;
	int				door;
	double			move_speed;
	int				key_move;
	int				map_lenx;
	int				map_leny;
	void			*mlx;
	void			*win;
	int				i;
	int				j;
	int				pv_cpy;
	t_img			img_win;
	t_textures_path	textures_path;
	t_textures		textures;
	t_map			*map_char;
	t_pos			pos;
	t_mousse		mouse;
	t_enemy			*enemy;
	t_info			info;
}	t_data;

typedef struct s_algo
{
	double	coef_camx;
	double	raydir_actx;
	double	raydir_acty;
	int		map_posx;
	int		map_posy;
	double	delta_distx;
	double	delta_disty;
	double	dist_temp_rayx;
	double	dist_temp_rayy;
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
void			print_enemy_movement(t_data *data, int actual_enemy);

/*lst_function.c*/
void			ft_lstadd_back(t_map **lst, t_map *new);
t_map			*ft_lstlast(t_map *lst);
t_map			*ft_lstnew(void *content);
int				ft_lstsize(t_map *lst);

/*functions_plus*/
int				ft_atoi(const char *nptr);
int				get_args(t_data *data);
int				ft_strlen2(char **s);
size_t			ft_strcpy(char *dst, char *src);
char			**trunc_map(t_data *data);
int				check_map_valid(t_data *data);
void			flood_fill(char **tab, t_point *size,
					t_point *begin, t_data *data);
char			**map_dup(char **tab);
void			change_dis(t_point *dis, t_pos start, t_data *data, int cases);
int				check_colour(int *res);
void			ft_key_moves2(t_data *data, int *i);

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
void			ft_calc_delta(t_algo *algo, t_data *data, int x);
void			get_steps(int *stepX, int *stepY, t_algo *algo, t_data *data);

int				mouse_move(int x, int y, t_data *data);
int				mouse_left_click(int button, int x, int y, t_data *data);
void			draw_crossair(t_data *data);
int				door_check(t_data *data, t_algo *algo);
void			show_pov(t_data *data);
//void			build_sprite(t_data *data, dist wall);

/*build_img2.c*/
unsigned int	get_color(unsigned char R, unsigned char G, unsigned char B);
void			img_pixel_put(t_img *img, int x, int y, int color);
void			get_texture(t_algo *algo, int stepX, int stepY);
void			pix_texture(t_data *data, t_algo *algo, int *y);

/*build_sprite.c*/
void			build_sprite(t_data *data, double *dis_wall);
void			draw_sprite(t_data *data, t_point *draw,
					t_algo *spr, double *dis_wall);
int				get_nb_sprite(t_data *data);
int				sort_sprite2(t_data *data, int **order, double **dis);
void			act_text(t_data *data, t_algo *spr);

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
void			placing_enemy(t_data *data);
void			enemy_move(t_data *data);

/*hitbox*/
int				is_player_hitbox_touched(t_data *data, int actual_enemy);
int				check_side(int textx, t_algo *algo);
int				ft_key_moves(t_data *data);
void			move_diag(t_data *data);
void			check_door_spot(t_data *data);
void			placing_enemy(t_data *data);
int				door_check(t_data *data, t_algo *algo);
int				get_nb_sprite(t_data *data);
int				is_player_hitbox_touched(t_data *data, int actual_enemy);
void			display_heart(t_data *data);
int				check_extention(char *str, char *ext);
int				ft_max_size(char **str);

/*time*/
double			get_time(void);
int				check_arg_2(t_data *data);
#endif
