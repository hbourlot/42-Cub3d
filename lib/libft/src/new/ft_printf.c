/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:51:20 by hbourlot          #+#    #+#             */
/*   Updated: 2024/11/06 15:10:59 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	number_base(long nbr, char *fmt)
{
	int	i;
	int	len;

	len = ft_strlen(fmt);
	i = 0;
	if (nbr < 0)
	{
		ft_putchar('-');
		return (number_base(-nbr, fmt) + 1);
	}
	if (nbr >= len)
	{
		i = number_base(nbr / len, fmt);
		return (i + number_base(nbr % len, fmt));
	}
	else
		return (ft_putchar(fmt[nbr]));
}

int	base_p_negative(unsigned long nbr, char *fmt)
{
	int	i;
	int	len;

	len = ft_strlen(fmt);
	i = 0;
	if (nbr >= 16)
	{
		i = base_p_negative(nbr / len, fmt);
		return (i + base_p_negative(nbr % len, fmt));
	}
	else
		return (ft_putchar("0123456789abcdef"[nbr]));
}

int	handle_flags(long nbr, char fmt, char *base)
{
	if (fmt == 'p' && nbr <= 0)
	{
		if (nbr == 0)
			return (ft_putstr("(nil)"));
		return (ft_putstr("Ox") + base_p_negative(nbr, base));
	}
	else if (fmt == 'p')
		return (ft_putstr("Ox") + base_p_negative(nbr, base));
	else if (fmt == 'x' || fmt == 'X')
		return (number_base(nbr, base));
	else
		return (number_base(nbr, base));
}

int	ft_format(const char *fmt, va_list *ap)
{
	int	i;

	i = 0;
	if (fmt[0] == 'c')
		i += ft_putchar(va_arg(*ap, int));
	else if (fmt[0] == 's')
		i += ft_putstr(va_arg(*ap, char *));
	else if (fmt[0] == 'p')
		i += handle_flags((long)va_arg(*ap, unsigned long), 'p',
				"0123456789abcdef");
	else if (fmt[0] == 'd' || fmt[0] == 'i')
		i += handle_flags(va_arg(*ap, int), 'i', "0123456789");
	else if (fmt[0] == 'u')
		i += handle_flags(va_arg(*ap, unsigned int), 'u', "0123456789");
	else if (fmt[0] == 'X')
		i += handle_flags(va_arg(*ap, unsigned int), 'X', "0123456789ABCDEF");
	else if (fmt[0] == 'x')
		i += handle_flags(va_arg(*ap, unsigned int), 'x', "0123456789abcdef");
	else if (fmt[0] == '%')
		i += ft_putchar('%');
	return (i);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		i;
	int		result;

	if (fmt == NULL)
		return (-1);
	va_start(ap, fmt);
	result = 0;
	i = 0;
	while (*fmt)
	{
		if (*fmt == '%')
			result += ft_format(++fmt, &ap);
		else
		{
			ft_putchar(*fmt);
			i++;
		}
		fmt++;
	}
	va_end(ap);
	return (result + i);
}
