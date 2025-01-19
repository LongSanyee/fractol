/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rammisse <rammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:50:12 by rammisse          #+#    #+#             */
/*   Updated: 2025/01/17 15:54:39 by rammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	handle_leaks(void *mlx_ptr, void *win_ptr, void *img_ptr)
{
	if (img_ptr)
		mlx_destroy_image(mlx_ptr, img_ptr);
	if (win_ptr)
		mlx_destroy_window(mlx_ptr, win_ptr);
	if (mlx_ptr)
		mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
}

static void	setup_data(t_data *data, int type, t_complex c)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Fract'ol");
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bpp,
			&data->line_len, &data->endian);
	data->offset_x = 0.0;
	data->offset_y = 0.0;
	data->type = type;
	data->color_shift = 0;
	data->c = c;
	data->zoom = 1.0;
}

static int	handle_hooks(int keycode, t_data *data)
{
	if (keycode == 65307)
	{
		handle_leaks(data->mlx, data->win, data->img);
		exit(0);
	}
	else if (keycode == 65361)
		data->offset_x -= 10.0;
	else if (keycode == 65363)
		data->offset_x += 10.0;
	else if (keycode == 65364)
		data->offset_y += 10.0;
	else if (keycode == 65362)
		data->offset_y -= 10.0;
	else if (keycode == 32)
		data->color_shift = (data->color_shift + 10) % RED;
	render(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

static int	close_window(t_data *data)
{
	handle_leaks(data->mlx, data->win, data->img);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data		data;
	t_complex	c;

	c.im = 0.0;
	c.re = 0.0;
	if (argc < 2 || (ft_strcmp(argv[1], "mandelbrot") != 0
			&& (ft_strcmp(argv[1], "julia") != 0 || argc != 4)))
		errormsg();
	else if (ft_strcmp(argv[1], "mandelbrot") == 0 && argc == 2)
		data.type = 0;
	else if (ft_strcmp(argv[1], "julia") == 0 && argc == 4)
	{
		data.type = 1;
		c.re = ft_atod(argv[2]);
		c.im = ft_atod(argv[3]);
	}
	setup_data(&data, data.type, c);
	render(&data);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_key_hook(data.win, handle_hooks, &data);
	mlx_mouse_hook(data.win, handlemouse, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_loop(data.mlx);
	return (0);
}
