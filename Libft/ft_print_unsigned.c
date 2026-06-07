/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamed-i <ali.hamed-ibrahim@learner.42.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 16:18:15 by ahamed-i          #+#    #+#             */
/*   Updated: 2026/06/04 17:35:35 by ahamed-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

int	ft_print_unsigned(unsigned int n)
{
	return (ft_putnbr_base((unsigned long)n, "0123456789"));
}
