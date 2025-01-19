/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rammisse <rammisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:46:13 by rammisse          #+#    #+#             */
/*   Updated: 2025/01/17 13:16:53 by rammisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	errormsg(void)
{
	ft_putstr_fd(ERR, 2);
	exit(0);
}

static int	check_valid_argument(const char *str)
{
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
		str++;
	if (*str < '0' || *str > '9')
		return (0);
	while (*str >= '0' && *str <= '9')
		str++;
	if (*str == '.')
	{
		str++;
		while (*str >= '0' && *str <= '9')
			str++;
	}
	if (*str != '\0')
		return (0);
	return (1);
}

static void	handle(char **str, double *sign)
{
	if (**str == '-')
		*sign = -1.0;
	(*str)++;
}

double	ft_atod(char *str)
{
	double	result;
	double	sign;
	double	fraction;

	result = 0.0;
	sign = 1.0;
	fraction = 1.0;
	if (!check_valid_argument(str))
		errormsg();
	if (*str == '-' || *str == '+')
		handle(&str, &sign);
	while (*str >= '0' && *str <= '9')
		result = result * 10 + (*str++ - '0');
	if (*str == '.')
	{
		str++;
		while (*str >= '0' && *str <= '9')
		{
			fraction *= 0.1;
			result += (*str++ - '0') * fraction;
		}
	}
	return (result * sign);
}
