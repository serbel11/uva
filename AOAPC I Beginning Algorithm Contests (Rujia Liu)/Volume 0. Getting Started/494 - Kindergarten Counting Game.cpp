#include <stdio.h>
int main()
{
	char str[255];
	while (gets(str)){
		int i, count = 0;
		for (i = 0; str[i] != '\0'; i++){
			if (((str[i] >= 97) && (str[i] <= 122)) || ((str[i] >= 65) && (str[i] <= 90)))
				if (((str[i + 1] < 97) || (str[i + 1] > 122)) && ((str[i + 1] < 65) || (str[i + 1] > 90)))
				count++;
		}
		printf("%d\n", count);
	}
}