#include <stdio.h>
int main()
{
	int i, j, k, h, num, ampl, freq;
	scanf("%d", &num);

	for (i = 0; i < num; i++){
		if (i != 0)
			putchar(10);
		scanf("%d", &ampl);
		scanf("%d", &freq);
		for (j = 0; j < freq; j++){
			if (j != 0) 
				putchar(10);
			for (k = 1; k < ampl; k++){
				int h;
				for (h = 0; h < k; h++){
					putchar(k + 48);
				}
				putchar(10);
			}
			for (k = ampl; k >= 1; k--){
				for (h = 0; h < k; h++){
					putchar(k + 48);
				}
				putchar(10);
			}
		}
	}
	return 0;
}