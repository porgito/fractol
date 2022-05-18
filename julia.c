/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:51:12 by jlaurent          #+#    #+#             */
/*   Updated: 2022/01/08 02:28:54 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	initstruct_julia(t_data *data)
{
	data->c = 0;
	data->x1 = -1;
	data->y1 = -1.2;
	data->imax = 50;
	data->zoom = 270;
	data->color = 25;
	data->cr = 0.285;
	data->ci = 0.01;
	data->tmpzoom = data->zoom;
	data->tmpx1 = data->x1;
	data->tmpy1 = data->y1;
}

int	motion_julia(int x, int y, t_data *data)
{
	data->cr = (double)x / HAUTEUR * 4 - 2;
	data->ci = (double)y / HAUTEUR * 4 - 2;
	pthread_init(data);
	return (0);
}

void	julia(t_data *data)
{
	data->zr = data->x / data->zoom + data->x1;
	data->zi = data->y / data->zoom + data->y1;
	data->i = 0;
	while ((data->zr * data->zr) + (data->zi
			* data->zi) < 4 && data->i < data->imax)
	{
		data->temp = data->zr;
		data->zr = data->temp * data->temp
			- data->zi * data->zi + data->cr;
		data->zi = (2 * data->zi * data->temp) + data->ci;
		data->i++;
	}
	if (data->i == data->imax)
		pixelput(data, data->x, data->y, data->color);
	else
		pixelput(data, data->x, data->y, data->color * data->i);
}

void	*jul(void *tab)
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
			julia(data);
			data->y++;
		}
		data->x++;
	}
	return (tab);
}

void	pthread_julia(t_data *data)
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
		pthread_create(&t[i], NULL, jul, &tab[i]);
		i++;
	}
	while (i--)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
