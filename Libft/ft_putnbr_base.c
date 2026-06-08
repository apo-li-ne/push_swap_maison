/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolguil <apolguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 14:30:49 by ahamed-i          #+#    #+#             */
/*   Updated: 2026/06/08 22:53:13 by apolguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_base(unsigned long nb, char *base)
{
	int	count;
	int	base_len;

	base_len = 0;
	while (base[base_len])
		base_len++;
	count = 0;
	if (nb >= (unsigned long)base_len)
		count += ft_putnbr_base((nb / base_len), base);
	count += write(1, &base[nb % base_len], 1);
	return (count);
}
