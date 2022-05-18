/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:24:01 by jlaurent          #+#    #+#             */
/*   Updated: 2022/05/03 15:05:05 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	initstruct_mandelbrot(t_data *data)
{
	data->c = 0;
	data->x1 = -2;
	data->y1 = -1.2;
	data->zoom = 220;
	data->imax = 50;
	data->tmpx1 = data->x1;
	data->tmpy1 = data->y1;
	data->tmpzoom = data->zoom;
	data->color = 0x020000;
}

void	mandelbrot(t_data *data)
{
	data->zr = 0;
	data->zi = 0;
	data->cr = data->x / data->zoom + data->x1;
	data->ci = data->y / data->zoom + data->y1;
	data->i = 0;
	while ((data->zr * data->zr) + (data->zi
			+ data->zi) < 4 && data->i < data->imax)
	{
		data->temp = data->zr;
		data->zr = (data->temp * data->temp) - (data->zi * data->zi) + data->cr;
		data->zi = (2 * data->zi * data->temp) + data->ci;
		data->i++;
	}
	if (data->i == data->imax)
		pixelput(data, data->x, data->y, data->color);
	else
		pixelput(data, data->x, data->y, data->color * data->i);
}

void	*mandel(void *tab)
{
	t_data	*data;
	int		tmp;

	data = (t_data *)tab;
	data->x = 0;
	tmp = data->y;
	while (data->x < LARGEUR - 200)
	{
		data->y = tmp;
		while (data->y < data->y_max)
		{
			mandelbrot(data);
			data->y++;
		}
		data->x++;
	}
	return (tab);
}

void	pthread_mandelbrot(t_data *data)
{
	t_data		tab[120];
	pthread_t	t[120];
	int			i;

	i = 0;
	while (i < 120)
	{
		ft_memcpy((void *)&tab[i], (void *)data, sizeof(t_data));
		tab[i].y = 5 * i;
		tab[i].y_max = 5 * (i + 1);
		pthread_create(&t[i], NULL, mandel, &tab[i]);
		i++;
	}
	while (i--)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
