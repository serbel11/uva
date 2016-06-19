#include <stdio.h>
int main()
{
	unsigned long int hashmat, opponent;
		
	while (scanf("%lu %lu", &hashmat, &opponent) == 2) 
	{
		if (hashmat > opponent)
			printf("%lu\n", (hashmat - opponent));
		else
			printf("%lu\n", (opponent - hashmat));
	}
	return 0;
}