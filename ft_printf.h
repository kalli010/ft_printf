

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_putunsigned(unsigned int n);
int	ft_putpointer(unsigned long long num);
int	ft_putX(unsigned int d, unsigned int base);
int	ft_putx(unsigned int d,unsigned int base);
int	ft_putnbr(int num);
int	ft_printf(const char *format, ...);
int	ft_putstr(char *s);
int	ft_putchar(int c);

#endif
