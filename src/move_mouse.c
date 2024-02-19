#include "../inc/cube3d.h"

int	mouse_move(int x, int y, t_data *data)
{
	int		x_distance;
	double	rot_coef;
	(void)y;

	x_distance = 0;
	if (x < (WIN_X / 2))
		x_distance = x - (WIN_X / 2);
	else if (x > (WIN_X / 2))
		x_distance = x - (WIN_X / 2);
	rot_coef = (double)x_distance / (double)SENSIVITY;
	//printf("rot_coef = %f | x_distance = %i | SENSITIVITY = %i\n", rot_coef, x_distance, SENSIVITY);
	ft_rotation(data, rot_coef);
	set_mouse_center_screen(data);
	build_img(data);
	return (0);
}

// void	get_m_x_y(t_data *data, int x, int y)
// {
// 	int		i = 0;
// 	while (data->mouse_posx < x)
// 	{
// 		data->mouse_posx += 16;
// 		i++;
// 	}
// 	data->mouse_posx = i - 1;
// 	i = 0;
// 	while (data->mouse_posy < y)
// 	{
// 		data->mouse_posy += 16;
// 		i++;
// 	}
// 	data->mouse_posy = i - 1;
// 	i = 0;
// 	data->image__posx = (data->mouse_posx * 16);
// 	data->image__posy = (data->mouse_posy * 16);
// }
// int	change_fov(int key, t_data *data)
// {
// 	printf("key = %i\n", key);
// 	if (key == 4)
// 	{
// 		data->i = 1;
// 		// if (!data->pos.norm_camX)
// 		// 	printf("hey\n");
// 		// data->pos.norm_camX = data->pos.norm_camX * 1;
// 		// data->pos.norm_camY = data->pos.norm_camY * 1;
// 		printf("coucou\n");
// 	}
// 	else if (key == 5)
// 	{
// 		data->i = 2;
// 		printf("aurevoir\n");
// 		// data->pos.norm_camX = data->pos.norm_camX * 1;
// 		// data->pos.norm_camY = data->pos.norm_camY * 1;
// 	}
// 	return (0);
// }
