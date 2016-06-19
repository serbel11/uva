#include <stdio.h>
int main()
{
	signed char v;
	unsigned char t;
		
	while (scanf("%i %i", &v, &t) == 2)
	{
		printf("%i\n", 2 * v * t);
	}
	return 0;
}