/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamed-i <ali.hamed-ibrahim@learner.42.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 16:21:46 by ahamed-i          #+#    #+#             */
/*   Updated: 2026/06/04 17:35:09 by ahamed-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

int	ft_print_hex(unsigned int n, char format)
{
	if (format == 'X')
		return (ft_putnbr_base((unsigned long)n, "0123456789ABCDEF"));
	return (ft_putnbr_base((unsigned long)n, "0123456789abcdef"));
}
