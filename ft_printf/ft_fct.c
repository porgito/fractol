/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: porg <porg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:33:14 by porg              #+#    #+#             */
/*   Updated: 2021/11/24 15:41:56 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_putchar(t_print *tab, char c)
{
	tab->tl += write(1, &c, 1);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(t_print *tab, char const *str)
{
	int		i;

	if (!str)
		str = "(null)";
	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	tab->tl += ft_strlen(str);
}

void	ft_putuns(t_print *tab, unsigned int n)
{
	if (n > 9)
		ft_putuns(tab, n / 10);
	ft_putchar(tab, n % 10 + '0');
}
