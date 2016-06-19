#include <stdio.h>
int main()
{
	char codech;	
	while ((codech = getchar ()) != EOF) {
		if (codech != 10)
			codech -= 7;
		putchar(codech);
	}
	return 0;
}