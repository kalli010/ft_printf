/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelkalai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:10:06 by zelkalai          #+#    #+#             */
/*   Updated: 2023/12/08 16:10:07 by zelkalai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	my_printf(const char *format, va_list ap)
{
	int c;

	c = 0;
	else if(format == 'c')
		c += ft_putchar(va_arg(ap, int));
	else if(format == 's')
		c += ft_putstr(va_arg(ap, char *));
	else if(format == 'd')
		c += ft_putnbr(va_arg(ap, int));
	else if(format == 'i')
		c += ft_putnbr(va_arg(ap, int));
	else if(format == 'x')
		c += ft_putx(va_arg(ap, unsigned int), format);
	else if(format == 'X')
		c += ft_putx(va_arg(ap, unsigned int), format);
	else if(format == 'p')
		c += ft_putpointer(va_arg(ap, unsigned long long));
	else if(format == 'u')
		c += ft_putunsigned(va_arg(ap, unsigned int));
	else if(format == '%')
		c += ft_putchar('%');
	return (c);
}

int	printf( const char *restrict format, ... )
{
	va_list pa;
	int c;

	c = 0;
	va_start(ap, foramt);
	while (*format)
	{
		if(format == '%')
		{
			format++;
			c += my_printf(*format, ap);
		}
		else 
			c += write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (c);
}
