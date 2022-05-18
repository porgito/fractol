/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:59:32 by jlaurent          #+#    #+#             */
/*   Updated: 2022/01/08 04:08:19 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	juliaonly(t_data *data)
{
	mlx_string_put(data->mlx, data->win, 600, 340, 0xFFFFFF,
		" ---------------------------");
	mlx_string_put(data->mlx, data->win, 665, 350, 0xFF0000,
		"JULIA ONLY");
	mlx_string_put(data->mlx, data->win, 600, 360, 0xFFFFFF,
		" ---------------------------");
	mlx_string_put(data->mlx, data->win, 615, 395, 0xFFFFFF,
		"Start Motion : Left Click");
	mlx_string_put(data->mlx, data->win, 615, 425, 0xFFFFFF,
		"Freeze : Right Click");
}

void	activefractal(t_data *data)
{
	if (data->fractal == 1)
		mlx_string_put(data->mlx, data->win, 650, 255, 0x00FF00,
			"MANDELBROT");
	else
		mlx_string_put(data->mlx, data->win, 650, 255, 0xFFFFFF,
			"Mandelbrot : 1");
	if (data->fractal == 2)
		mlx_string_put(data->mlx, data->win, 650, 280, 0x00FF00,
			"JULIA");
	else
		mlx_string_put(data->mlx, data->win, 650, 280, 0xFFFFFF,
			"Julia : 2");
	if (data->fractal == 3)
		mlx_string_put(data->mlx, data->win, 650, 300, 0x00FF00,
			"BURNING SHIP");
	else
		mlx_string_put(data->mlx, data->win, 650, 300, 0xFFFFFF,
			"Burning Ship : 3");
}

void	drawtext(t_data *data)
{
	mlx_string_put(data->mlx, data->win, 685, 28, 0xFFFFFF, "MENU");
	mlx_string_put(data->mlx, data->win, 600, 45, 0xFFFFFF,
		" ---------------------------");
	mlx_string_put(data->mlx, data->win, 615, 80, 0xFFFFFF,
		"Zoom : Mouse Wheel");
	mlx_string_put(data->mlx, data->win, 615, 110, 0xFFFFFF, "Move : Arrows");
	mlx_string_put(data->mlx, data->win, 615, 140, 0xFFFFFF,
		"Change colors : C");
	mlx_string_put(data->mlx, data->win, 615, 170, 0xFFFFFF,
		"Add 10 iterations : V");
	mlx_string_put(data->mlx, data->win, 615, 200, 0xFFFFFF,
		"Remove 10 iterations : B");
	mlx_string_put(data->mlx, data->win, 615, 230, 0xFFFFFF,
		"Change fractal : 1, 2, 3");
	activefractal(data);
	juliaonly(data);
	mlx_string_put(data->mlx, data->win, 600, 570, 0xFFFFFF,
		" ---------------------------");
	mlx_string_put(data->mlx, data->win, 615, 585, 0xFFFFFF, "Quit : Escape");
}

void	drawmenu(t_data *data)
{
	int	x;
	int	y;
	int	w;
	int	tmp;

	x = LARGEUR - 200;
	y = 0;
	tmp = x;
	while (y < HAUTEUR)
	{
		while (x < LARGEUR)
		{
			if (y < 6 || y > 594)
				pixelput(data, x, y, 0xFFFFFF);
			else if (x < tmp + 6 || x > LARGEUR - 6)
				pixelput(data, x, y, 0xFFFFFF);
			x++;
		}
		if (x >= LARGEUR)
			x = tmp;
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	drawtext(data);
}
