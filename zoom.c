/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 20:10:52 by jlaurent          #+#    #+#             */
/*   Updated: 2022/01/10 20:12:53 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoomin(int x, int y, t_data *data)
{
	data->x1 = ((double)x / data->zoom + data->x1)
		- ((double)x / (data->zoom * 1.1));
	data->y1 = ((double)y / data->zoom + data->y1)
		- ((double)y / (data->zoom * 1.1));
}

void	zoomout(int x, int y, t_data *data)
{
	data->x1 = ((double)x / data->zoom + data->x1)
		- ((double)x / (data->zoom - (data->zoom * 1.1 - data->zoom)));
	data->y1 = ((double)y / data->zoom + data->y1)
		- ((double)y / (data->zoom - (data->zoom * 1.1 - data->zoom)));
}
