/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fct2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: porg <porg@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:42:11 by porg              #+#    #+#             */
/*   Updated: 2021/11/24 16:02:36 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putbase(t_print *tab, unsigned int n, char *base);
void	ft_putbaseptr(t_print *tab, unsigned long n, char *base);

void	ft_base(t_print *tab, unsigned int n, char c)
{
	if (c == 'x')
		ft_putbase(tab, n, "0123456789abcdef");
	if (c == 'X')
		ft_putbase(tab, n, "0123456789ABCDEF");
}

void	ft_putbase(t_print *tab, unsigned int n, char *base)
{
	if (n >= 16)
		ft_putbase(tab, n / 16, base);
	ft_putchar(tab, base[n % 16]);
}

void	ft_putptr(t_print *tab, unsigned long n)
{
	ft_putstr(tab, "0x");
	ft_putbaseptr(tab, n, "0123456789abcdef");
}

void	ft_putbaseptr(t_print *tab, unsigned long n, char *base)
{
	if (n >= 16)
		ft_putbaseptr(tab, n / 16, base);
	ft_putchar(tab, base[n % 16]);
}
