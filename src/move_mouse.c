#include "../inc/cube3d.h"

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
int	change_fov(int key, t_data *data)
{
	printf("key = %i\n", key);
	if (key == 4)
	{
		data->pos.norm_camX = data->pos.norm_camX * 0.99;
		data->pos.norm_camY = data->pos.norm_camY * 0.99;
	}
	else if (key == 5)
	{
		data->pos.norm_camX = data->pos.norm_camX * 1.01;
		data->pos.norm_camY = data->pos.norm_camY * 1.01;
	}
	return (0);
}
