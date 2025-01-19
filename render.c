/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rammisse <rammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:43:05 by rammisse          #+#    #+#             */
/*   Updated: 2025/01/17 13:13:57 by rammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render_mandelbrot(t_data *data)
{
	int		x;
	int		y;
	double	scale;
	double	real;
	double	imag;

	scale = 4.0 / WIDTH / data->zoom;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			real = (x - WIDTH / 2) * scale + data->offset_x * scale;
			imag = (y - HEIGHT / 2) * scale + data->offset_y * scale;
			put_pixel(data, x, y, get_color(mandelbrot(real, imag)
					+ data->color_shift));
			x++;
		}
		y++;
	}
}

void	render_julia(t_data *data)
{
	int		x;
	int		y;
	double	scale;
	double	real;
	double	imag;

	scale = 2.0 / (WIDTH / 2) * data->zoom;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			real = (x - WIDTH / 2) * scale + data->offset_x * scale;
			imag = (y - HEIGHT / 2) * scale + data->offset_y * scale;
			put_pixel(data, x, y, get_color(julia(real, imag, data->c)
					+ data->color_shift));
			x++;
		}
		y++;
	}
}

void	render(t_data *data)
{
	if (data->type == 0)
		render_mandelbrot(data);
	else if (data->type == 1)
		render_julia(data);
}
