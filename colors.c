/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 19:40:50 by jlaurent          #+#    #+#             */
/*   Updated: 2022/01/08 04:18:39 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	colorchange(int key, t_data *data)
{
	const int	color[15] = {0xE67E30, 0x88421D, 0xA76726, 0x91283B,
		0x884DA7, 0x007FFF, 0x2C75FF, 0x0F056B, 0x2F1B0C, 0x462E01,
		0x801818, 0xA91101, 0xFF0921, 0xFAEA73, 0x95A595};

	if (data->c == 16)
		data->c = 0;
	data->color = color[data->c++];
	pthread_julia(data);
}
