/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rammisse <rammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:44:52 by rammisse          #+#    #+#             */
/*   Updated: 2025/01/17 14:36:27 by rammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx/mlx.h"
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 600
# define HEIGHT 600
# define MAX_ITER 60
# define RED 0xFFFFFF
# define ERR "valid input: ./fractol mandelbrot or ./fractol julia <c1> <c2>\n"

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bpp;
	double		offset_x;
	double		offset_y;
	int			line_len;
	double		zoom;
	int			type;
	int			endian;
	int			color_shift;
	t_complex	c;
}	t_data;

double		complex_magnitude(t_complex z);
t_complex	complex_square(t_complex z);
int			mandelbrot(double x, double y);
int			julia(double x, double y, t_complex c);
void		render_julia(t_data *data);
void		render_mandelbrot(t_data *data);
void		render(t_data *data);
void		errormsg(void);
double		ft_atod(char *str);
void		put_pixel(t_data *data, int x, int y, int color);
int			handlemouse(int button, int x, int y, t_data *data);
void		ft_putstr_fd(char *s, int fd);
int			ft_strcmp(const char *s1, const char *s2);
int			get_color(int iter);

#endif
