/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolguil <apolguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 16:21:46 by ahamed-i          #+#    #+#             */
/*   Updated: 2026/06/08 22:52:21 by apolguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_hex(unsigned int n, char format)
{
	if (format == 'X')
		return (ft_putnbr_base((unsigned long)n, "0123456789ABCDEF"));
	return (ft_putnbr_base((unsigned long)n, "0123456789abcdef"));
}
