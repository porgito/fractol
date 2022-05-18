/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louis <louis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 15:02:43 by louis             #+#    #+#             */
/*   Updated: 2022/03/02 16:20:43 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define ESC			53
# define UP				126
# define DOWN			125
# define LEFT			123
# define RIGHT			124
# define ONE			18
# define TWO			19
# define THREE			20
# define C				8
# define V				9
# define B				11
# define SPACE			49

# define LARGEUR		800
# define HAUTEUR		600

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <pthread.h>
# include "./mlx/mlx.h"
# include "./ft_printf/ft_printf.h"

typedef struct s_data{
	void	*mlx;
	void	*win;
	int		fractal;
	void	*img;
	void	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		c;
	int		x;
	int		y;
	int		y_max;
	int		color;
	int		i;
	int		imax;
	int		mouse;
	double	zoom;
	double	zr;
	double	zi;
	double	cr;
	double	ci;
	double	temp;
	double	x1;
	double	y1;
	double	tmpzoom;
	double	tmpx1;
	double	tmpy1;
}				t_data;

//LIBFT//
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		ft_strcmp(const char *str1, const char *str2);
//MANDELBROT//
void	initstruct_mandelbrot(t_data *data);
void	pthread_mandelbrot(t_data *data);
void	*mandel(void *tab);
void	mandelbrot(t_data *data);
//JULIA//
void	initstruct_julia(t_data *data);
void	pthread_julia(t_data *data);
void	*jul(void *tab);
void	julia(t_data *data);
int		motion_julia(int x, int y, t_data *data);
//BURNINGSHIP//
void	initstruct_burningship(t_data *data);
void	pthread_burningship(t_data *data);
void	*burning(void *tab);
void	burningship(t_data *data);
//FCT//
void	check_fract(t_data *data, char *arv[]);
void	initstruct(t_data *data);
void	pthread_init(t_data *data);
void	colorchange(int key, t_data *data);
void	changefractal(int key, t_data *data);
void	pixelput(t_data *data, int x, int y, int color);
void	zoomin(int x, int y, t_data *data);
void	zoomout(int x, int y, t_data *data);
//HOOKS//
int		key_hook(int key, t_data *data);
int		mouse_hook(int mouse, int x, int y, t_data *data);
//MENU//
void	drawmenu(t_data *data);
void	drawtext(t_data *data);
void	activefractal(t_data *data);
void	juliaonly(t_data *data);

#endif
