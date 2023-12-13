#include "ft_printf.c"

int	main(void)
{
	int	num;

	/*  // Test ft_putchar
		printf("Testing ft_putchar:\n");
		ft_putchar('A');
		ft_putchar('\n');
		// Test ft_putstr
		printf("Testing ft_putstr:\n");
		ft_putstr("Hello, World!");
		ft_putchar('\n');
		// Test ft_putnbr with various numbers
		printf("Testing ft_putnbr:\n");
		ft_putnbr(12345);
		ft_putchar('\n');
		ft_putnbr(-12345);
		ft_putchar('\n');
		ft_putnbr(-2147483648); // Edge case
		ft_putchar('\n');
		ft_putnbr(2147483647); // Edge case
		ft_putchar('\n');
		putnbr(12345);
		putchar('\n');
		putnbr(-12345);
		putchar('\n');
		putnbr(-2147483648); // Edge case
		putchar('\n');
		putnbr(2147483647); // Edge case
		putchar('\n');
		// Test ft_putx and ft_putX (hexadecimal)
		printf("Testing ft_putx and ft_putX:\n");
		ft_putx(0xABCDEF, 16);
		ft_putchar('\n');
		ft_putX(0xABCDEF, 16);
		ft_putchar('\n');
		putx(0xABCDEF, 16);
		putchar('\n');
		putX(0xABCDEF, 16);
		putchar('\n');
		// Test ft_putpointer
		printf("Testing ft_putpointer:\n");
		*/
	num = 12345;
	/*
	ft_putpointer((unsigned long long)(&num));
	ft_putchar('\n');
	putpointer((unsigned long long)(&num));
	putchar('\n');
	// Test ft_putunsigned
	printf("Testing ft_putunsigned:\n");
	ft_putunsigned(12345);
	ft_putchar('\n');
	putunsigned(12345);
	putchar('\n');
	ft_putunsigned(4294967295u); // Max unsigned int
	ft_putchar('\n');
	putunsigned(4294967295u); // Max unsigned int
	putchar('\n');
*/
	// Test custom printf with various format specifiers
	printf("Testing custom printf:\n");
	ft_printf("Char: %c, String: %s, Int: %d, Unsigned: %u, Hex: %x, HEX: %X,
		Pointer: %p\n", NULL, NULL, NULL, NULL, NULL, NULL, NULL);
	printf("Char: %c, String: %s, Int: %d, Unsigned: %u, Hex: %x, HEX: %X,
		Pointer: %p\n", NULL, NULL, NULL, NULL, NULL, NULL, 0);
	printf("test\n");
	ft_printf("%0");
	ft_printf("\n");
	printf("\n");
	printf("%0");
	return (0);
}
