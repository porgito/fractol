/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louis <louis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 20:07:10 by louis             #+#    #+#             */
/*   Updated: 2022/03/02 16:20:25 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	initstruct(t_data *data)
{
	if (data->fractal == 1)
		initstruct_mandelbrot(data);
	else if (data->fractal == 2)
		initstruct_julia(data);
	else if (data->fractal == 3)
		initstruct_burningship(data);
}

void	check_fract(t_data *data, char *argv[])
{
	data->fractal = 0;
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
		data->fractal = 1;
	else if (ft_strcmp(argv[1], "julia") == 0)
		data->fractal = 2;
	else if (ft_strcmp(argv[1], "burningship") == 0)
		data->fractal = 3;
	else
	{
		ft_printf("Le paramètre fourni est invalide.\nListe des paramètres"
			" valides:\n1: ./fractol mandelbrot\n2: ./fractol julia\n"
			"3: ./fractol burningship\n");
		exit (1);
	}
}

void	pthread_init(t_data *data)
{
	if (data->fractal == 1)
		pthread_mandelbrot(data);
	else if (data->fractal == 2)
		pthread_julia(data);
	else if (data->fractal == 3)
		pthread_burningship(data);
	drawmenu(data);
}

void	pixelput(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	main(int argc, char *argv[])
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (-1);
	if (argc != 2)
	{
		ft_printf("Le paramètre fourni est invalide.\nListe des paramètres"
			" valides:\n1: ./fractol mandelbrot\n2: ./fractol julia\n"
			"3: ./fractol burningship\n");
		return (0);
	}
	check_fract(data, argv);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, LARGEUR, HAUTEUR, "fract'ol");
	data->img = mlx_new_image(data->mlx, LARGEUR, HAUTEUR);
	data->addr = mlx_get_data_addr(data->img, &data->bpp,
			&data->line_length, &data->endian);
	initstruct(data);
	pthread_init(data);
	mlx_key_hook(data->win, key_hook, data);
	mlx_mouse_hook(data->win, mouse_hook, data);
	mlx_do_key_autorepeaton(data->mlx);
	mlx_loop(data->mlx);
	return (0);
}
