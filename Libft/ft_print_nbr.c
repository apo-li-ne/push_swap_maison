/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolguil <apolguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 15:40:45 by ahamed-i          #+#    #+#             */
/*   Updated: 2026/06/08 22:52:29 by apolguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_nbr(int n)
{
	int				count;
	unsigned int	nb;

	count = 0;
	if (n < 0)
	{
		count += write(1, "-", 1);
		nb = (unsigned int)(-(long)n);
	}
	else
		nb = (unsigned int)n;
	count += ft_putnbr_base((unsigned long)nb, "0123456789");
	return (count);
}
