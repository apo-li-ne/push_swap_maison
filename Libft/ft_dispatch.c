/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apolguil <apolguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 16:27:04 by ahamed-i          #+#    #+#             */
/*   Updated: 2026/06/08 22:51:37 by apolguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_dispatch(char conv, va_list args)
{
	if (conv == 'c')
		return (ft_print_char(va_arg(args, int)));
	if (conv == 's')
		return (ft_print_str(va_arg(args, char *)));
	if (conv == 'p')
		return (ft_print_ptr(va_arg(args, void *)));
	if (conv == 'd' || conv == 'i')
		return (ft_print_nbr(va_arg(args, int)));
	if (conv == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned int)));
	if (conv == 'x' || conv == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), conv));
	if (conv == '%')
		return (ft_print_char('%'));
	return (0);
}
