#include <unistd.h>

void	print_bits(unsigned char octet)
{
	unsigned char bits;
	int i = 8;

	while (i--)
	{
		bits = (octet >> i & 1) + '0';
		write(1, &bits, 1);
	}
}
