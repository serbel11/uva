#include <stdio.h>
int main()
{
	char codech;
	int i, n;
	while ((scanf ("%d", &n)), n != 0) {
		getchar();
		int min = 25;
		int spaceCountStr, spaceCount = 0;
		for (i = 0; i < n; i++){
			spaceCountStr = 0;
			while ((codech = getchar()) != 10){
				if (codech == 32){
					spaceCount++;
					spaceCountStr++;
				}
			}
			if (spaceCountStr < min)
				min = spaceCountStr;
		}
		printf("%d\n", spaceCount - n * min);
	}
	return 0;
}