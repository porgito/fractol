/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:58:24 by jlaurent          #+#    #+#             */
/*   Updated: 2021/11/24 15:26:46 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_nbstr(t_print *tab, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		tab->tl += write(1, &str[i], 1);
		i++;
	}
}

int	longueur(int n)
{
	int				len;
	unsigned int	nb;

	len = 0;
	if (n < 0)
	{
		len = 1;
		nb = -n;
	}
	else
		nb = n;
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	if (n == 0)
		len = 1;
	return (len);
}

void	check_n(int n, unsigned int i, char *nb, long int len)
{
	if (n > 0)
	{
		while (len > 0)
		{
			nb[len - 1] = '0' + (i % 10);
			i /= 10;
			len--;
		}
	}
	if (n < 0)
	{
		while (len > 1)
		{
			nb[len - 1] = '0' + (i % 10);
			i /= 10;
			len--;
		}
	}
}

void	*ft_itoa(t_print *tab, int n)
{
	char			*nb;
	unsigned int	i;
	long int		len;

	len = longueur(n);
	nb = malloc(sizeof(char) * (len));
	if (!nb)
		return (NULL);
	nb[longueur(n)] = '\0';
	if (n == 0)
		nb[0] = '0';
	if (n < 0)
	{
		nb[0] = '-';
		i = -n;
	}
	else
		i = n;
	check_n(n, i, nb, len);
	ft_nbstr(tab, nb);
	free(nb);
	return (nb);
}
/*
int	main()
{
	char	*i;

	i = ft_itoa(-2147483648);
	printf("%s", i);
}*/
