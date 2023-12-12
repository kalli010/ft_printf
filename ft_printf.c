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

int ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int ft_putstr(char *s)
{
	int i;
	
	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

int ft_putnbr(int num)
{
	int digit_count;
    	int temp;

    	if (num < 0)
	{
        	ft_putchar('-');
        	if (num == -2147483648)
		{
            		ft_putnbr(num / 10);
            		ft_putchar('8');
            		return 11;
		}
        	num = -num;
    	}
    	if (num >= 10)
	{
        	ft_putnbr(num / 10);
    	}
    	ft_putchar(num % 10 + '0');
    	digit_count = 0;
    	temp = num;
    	while (temp > 0)
	{
        	digit_count++;
        	temp /= 10;
    	}
    	return digit_count;
}


int ft_putx(unsigned int d, int base)
{
	int c;
	char *s;

	s = "0123456789abcdef";
	c = 0;
	if (d < base)
		c += ft_putchar(s[d]);
	else
	{
		c += ft_putx(d / base, base);
		c += ft_putchar(s[d % base]);
	}
	return (c);
}

int ft_putX(int d, int base)
{
	int c;
	char *s;

	s = "0123456789ABCDEF";
	c = 0;
	if (d < base)
		return (ft_putchar(s[d]));
	else
	{
		c = ft_putX(d / base, base);
		return (c + ft_putchar(s[d % base]));
	}
}

int ft_putpointer(unsigned long long num)
{
    	char hex_string[16];
    	char *hex_digits = "0123456789abcdef";
    	int index;
	int count;
	int i;
	
	index = 15;
	count = 0;
    	hex_string[index--] = '\0';
	if (num == 0)
    	{
		hex_string[index] = '0';
    	}
    	while (num > 0)
	{
        	hex_string[index--] = hex_digits[num % 16];
        	num /= 16;
    	}
    	count += ft_putchar('0');
    	count += ft_putchar('x');
    	i = index + 1;
	while (hex_string[i] != '\0')
	{
        	count += ft_putchar(hex_string[i]);
    		i++;
	}
    	return count;
}

int ft_putunsigned(unsigned int n) {
   	 int count = 0;

    	if (n / 10 != 0)
    	{
        	count += ft_putunsigned(n / 10);
    	}
    	count += ft_putchar(n % 10 + '0'); 
    	return count;
}

int	my_printf(const char *format, va_list ap)
{
	int c;

	c = 0;
	if(*format == 'c')
		c += ft_putchar(va_arg(ap, int));
	else if(*format == 's')
		c += ft_putstr(va_arg(ap, char *));
	else if(*format == 'd')
		c += ft_putnbr(va_arg(ap, int));
	else if(*format == 'i')
		c += ft_putnbr(va_arg(ap, int));
	else if(*format == 'x')
		c += ft_putx(va_arg(ap, unsigned int), 16);
	else if(*format == 'X')
		c += ft_putX(va_arg(ap, unsigned int), 16);
	else if(*format == 'p')
		c += ft_putpointer(va_arg(ap, unsigned long long));
	else if(*format == 'u')
		c += ft_putunsigned(va_arg(ap, unsigned int));
	else if(*format == '%')
		c += ft_putchar('%');
	return (c);
}

int	printf( const char *restrict format, ... )
{
	va_list ap;
	int c;

	c = 0;
	va_start(ap, format);
	while (*format)
	{
		if(*format == '%')
		{
			format++;
			c += my_printf(format, ap);
		}
		else 
			c += write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (c);
}
