/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 11:54:47 by jlaurent          #+#    #+#             */
/*   Updated: 2021/12/25 17:58:54 by louis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned long		c;
	char				*d;
	char				*s;

	d = (char *) dst;
	s = (char *) src;
	c = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (c < n)
	{
		d[c] = s[c];
		c++;
	}
	return (dst);
}
/*
int	main()
{
	char str1[30] = "ab";
	char str2[3] = "oki";
	printf("str1 avant memcpy\n");
	puts (str1);

	ft_memcpy(str1, str2, 5);

	puts("str1 apres memcpy");
	puts(str1);
}*/
