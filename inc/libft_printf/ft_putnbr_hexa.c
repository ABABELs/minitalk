/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:10:47 by aabel             #+#    #+#             */
/*   Updated: 2022/12/19 15:34:17 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_hexa(unsigned long nbr, const char input, int init)
{
	char			*hexa;
	unsigned long	nbr_modulo;
	static int		n;

	n = init;
	if (input == 'X')
		hexa = "0123456789ABCDEF";
	else if (input == 'x' || input == 'p')
		hexa = "0123456789abcdef";
	if (nbr < 16 && n != -1)
	{
		nbr_modulo = nbr % 16;
		if (ft_putchar(hexa[nbr]) == -1)
			return (-1);
		n++;
		return (n);
	}
	else
		if (ft_putnbr_hexa(nbr / 16, input, n) == -1)
			return (-1);
	ft_putnbr_hexa(nbr % 16, input, n);
	return (n);
}
