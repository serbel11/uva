#include <stdio.h>
#include <string.h>
int main()
{
	char str[256][256];
	int max = 0, i, j, num = 0; 

	while (gets(str[num])){
		if (strlen(str[num]) > max)
			max = strlen(str[num]);	
		num++;
	}	
	for (i = 0; i < num; i++){
		for (j = strlen(str[i]); j < max; j++)
		{
			str[i][j] = ' ';
		}
	}	
	for (j = 0; j < max; j++){
		for (i = num - 1; i >= 0; i--){
			putchar(str[i][j]);
		}
		putchar(10);
	}
	return 0;
}
