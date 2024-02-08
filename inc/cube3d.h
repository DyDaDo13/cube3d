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

# define WIN_X 1080
# define WIN_Y 720

// typedef struct s_image
// {
	
// }	t_image;

typedef struct s_textures_path
{
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	int		*F;
	int		*C;
}t_textures_path;

typedef struct s_map
{
	char			*map_line;
	struct s_map	*next;
}	t_map;

typedef struct s_pos
{
	float		p_x;
	float		p_y;
}	t_pos;
typedef struct s_data
{
	char			**map;
	void			*mlx;
	void			*win;
	t_textures_path	textures;
	t_map			*map_char;
	t_pos			pos;
}	t_data;

/*free_all.c*/
/* ************************************************************************** */
void	free_map(char **map);
void	free_list(t_map **map);
void	free_all(t_data *data);

/*init_map.c*/
t_map	*init_map_struct(int fd);
void	remove_newlines(t_data data);
char	**get_map(int fd, t_data *data);
char	**init_map(char *path_map, t_data *data);

/*debug.c*/
void	print_map(char **map);
void	print_args(t_data *data);

/*lst_function.c*/
void	ft_lstadd_back(t_map **lst, t_map *new);
t_map	*ft_lstlast(t_map *lst);
t_map	*ft_lstnew(void *content);
int		ft_lstsize(t_map *lst);

/*functions_plus*/
int		ft_atoi(const char *nptr);
int	get_args(t_data *data);
size_t	ft_strlen2(char **s);
size_t	ft_strcpy(char *dst, char *src);
char	**trunc_map(t_data *data);

/*display.c*/
int	ft_display(t_data *data);

#endif