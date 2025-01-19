/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rammisse <rammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:45:40 by rammisse          #+#    #+#             */
/*   Updated: 2025/01/17 14:29:25 by rammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	complex_square(t_complex z)
{
	t_complex	result;

	result.re = z.re * z.re - z.im * z.im;
	result.im = 2 * z.re * z.im;
	return (result);
}

double	complex_magnitude(t_complex z)
{
	return (z.re * z.re + z.im * z.im);
}

int	mandelbrot(double x, double y)
{
	t_complex	z;
	t_complex	c;
	int			iter;

	c.re = x;
	c.im = y;
	z.re = 0;
	z.im = 0;
	iter = 0;
	while (complex_magnitude(z) <= 4 && iter < MAX_ITER)
	{
		z = complex_square(z);
		z.re += c.re;
		z.im += c.im;
		iter++;
	}
	return (iter);
}

int	julia(double x, double y, t_complex c)
{
	t_complex	z;
	int			iter;

	z.re = x;
	z.im = y;
	iter = 0;
	while (complex_magnitude(z) <= 4 && iter < MAX_ITER)
	{
		z = complex_square(z);
		z.re += c.re;
		z.im += c.im;
		iter++;
	}
	return (iter);
}
