/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 16:26:12 by jlaurent          #+#    #+#             */
/*   Updated: 2022/01/08 02:07:40 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	changefractal(int key, t_data *data)
{
	if (key == ONE)
		data->fractal = 1;
	if (key == TWO)
		data->fractal = 2;
	if (key == THREE)
		data->fractal = 3;
	initstruct(data);
}

int	key_hook(int key, t_data *data)
{
	if (key == ESC)
		exit(1);
	if (key == UP)
		data->y1 = data->y1 - 20 / data->zoom;
	if (key == DOWN)
		data->y1 = data->y1 + 20 / data->zoom;
	if (key == LEFT)
		data->x1 = data->x1 - 20 / data->zoom;
	if (key == RIGHT)
		data->x1 = data->x1 + 20 / data->zoom;
	if (key == C)
		colorchange(key, data);
	if (key == V)
		data->imax += 10;
	if (key == B)
		data->imax -= 10;
	if (key == ONE || key == TWO || key == THREE)
		changefractal(key, data);
	pthread_init(data);
	return (0);
}

int	mouse_hook(int mouse, int x, int y, t_data *data)
{
	if (mouse == 4)
	{
		zoomin(x, y, data);
		data->zoom = data->zoom * 1.1;
	}
	else if (mouse == 5)
	{
		zoomout(x, y, data);
		data->zoom = data->zoom - (data->zoom * 1.1 - data->zoom);
	}
	else if (mouse == 3)
	{
		data->zoom = data->tmpzoom;
		data->x1 = data->tmpx1;
		data->y1 = data->tmpy1;
	}
	else if (mouse == 1 && data->fractal == 2)
		mlx_hook(data->win, 6, 1L << 6, motion_julia, data);
	else if (mouse == 2 && data->fractal == 2)
		mlx_hook(data->win, 6, 1L << 6, NULL, data);
	pthread_init(data);
	return (0);
}
